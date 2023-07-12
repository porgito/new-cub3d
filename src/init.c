/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:15:26 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 16:29:12 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void	init_mallocs_to_null(t_all *all)
{
	all->pars.map = NULL;
	all->pars.north_wall = NULL;
	all->pars.south_wall = NULL;
	all->pars.west_wall = NULL;
	all->pars.east_wall = NULL;
	all->mlx = NULL;
	all->mlx_win = NULL;
	all->data.img = NULL;
	all->data.addr = NULL;
	all->ray.texture[0].img = NULL;
	all->ray.texture[1].img = NULL;
	all->ray.texture[2].img = NULL;
	all->ray.texture[3].img = NULL;
}

void	init_cub(t_all *all, char *map)
{
	init_mallocs_to_null(all);
	parsing(all, map);
	check_map(all);
	all->mlx = mlx_init();
	if (!all->mlx)
		free_exit(all, 1, "Malloc Error\n");
	init_textures(all);
	all->mlx_win = mlx_new_window(all->mlx, WIDTH,
			HEIGHT, "cub3D");
	if (!all->mlx_win)
		free_exit(all, 1, "Malloc Error\n");
	all->data.img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	if (!all->data.img)
		free_exit(all, 1, "Malloc Error\n");
	all->data.addr = mlx_get_data_addr(all->data.img, \
		&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian);
	all->data.addr2 = (int *)mlx_get_data_addr(all->data.img, \
		&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian);
	if (!all->data.addr)
		free_exit(all, 1, "Malloc Error\n");
}

void	init_angle(t_all *all)
{
	int	x;
	int	y;

	x = all->ray.p_pos.x;
	y = all->ray.p_pos.y;
	if (all->pars.map[y][x] == 'N')
		all->ray.angle = -PI / 2;
	if (all->pars.map[y][x] == 'S')
		all->ray.angle = PI / 2;
	if (all->pars.map[y][x] == 'E')
		all->ray.angle = 0;
	if (all->pars.map[y][x] == 'W')
		all->ray.angle = 1;
	all->ray.delta_pos.x = cos(all->ray.angle);
	all->ray.delta_pos.y = sin(all->ray.angle);
}

void	init_ray(t_all *all)
{
	// mlx_mouse_hide(all->mlx, all->mlx_win);
	all->mouse_pos = WIDTH / 2;
	set_player_position(all);
	all->keys[0] = 1;
	all->keys[1] = 1;
	all->keys[2] = 1;
	all->keys[3] = 1;
	all->keys[4] = 1;
	all->keys[5] = 1;
	init_angle(all);
	all->ray.dir_perp.x = sin(all->ray.angle + PI / 2);
	all->ray.dir_perp.y = cos(all->ray.angle + PI / 2);
	all->ray.time = 0;
	all->ray.camera_orientation = 0;
	all->ray.raydir.x = 0;
	all->ray.raydir.y = 0;
	all->ray.map_x = 0;
	all->ray.in_wall = 0;
}
