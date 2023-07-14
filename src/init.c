/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:15:26 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/14 13:26:55 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_mallocs_to_null(t_info *info)
{
	info->pars.map = NULL;
	info->pars.north_wall = NULL;
	info->pars.south_wall = NULL;
	info->pars.west_wall = NULL;
	info->pars.east_wall = NULL;
	info->mlx = NULL;
	info->mlx_win = NULL;
	info->data.img = NULL;
	info->data.addr = NULL;
	info->ray.texture[0].img = NULL;
	info->ray.texture[1].img = NULL;
	info->ray.texture[2].img = NULL;
	info->ray.texture[3].img = NULL;
}

void	init_cub(t_info *info, char *map)
{
	init_mallocs_to_null(info);
	parsing(info, map);
	check_map(info);
	info->mlx = mlx_init();
	if (!info->mlx)
		free_exit(info, 1, "Malloc Error\n");
	init_textures(info);
	info->mlx_win = mlx_new_window(info->mlx, WIDTH,
			HEIGHT, "cub3D");
	if (!info->mlx_win)
		free_exit(info, 1, "Malloc Error\n");
	info->data.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->data.img)
		free_exit(info, 1, "Malloc Error\n");
	info->data.addr = mlx_get_data_addr(info->data.img, \
		&info->data.bits_per_pixel, &info->data.line_l, \
		&info->data.endian);
	info->data.addr2 = (int *)mlx_get_data_addr(info->data.img, \
		&info->data.bits_per_pixel, &info->data.line_l, \
		&info->data.endian);
	if (!info->data.addr)
		free_exit(info, 1, "Malloc Error\n");
}

void	init_angle(t_info *info)
{
	int	x;
	int	y;

	x = info->ray.p_pos.x;
	y = info->ray.p_pos.y;
	if (info->pars.map[y][x] == 'N')
		info->ray.angle = -PI / 2;
	if (info->pars.map[y][x] == 'S')
		info->ray.angle = PI / 2;
	if (info->pars.map[y][x] == 'E')
		info->ray.angle = 0;
	if (info->pars.map[y][x] == 'W')
		info->ray.angle = 1;
	info->ray.delta_pos.x = cos(info->ray.angle);
	info->ray.delta_pos.y = sin(info->ray.angle);
}

void	init_ray(t_info *info)
{
	mlx_mouse_hide(info->mlx, info->mlx_win);
	info->mouse_pos = WIDTH / 2;
	set_player_position(info);
	info->keys[0] = 1;
	info->keys[1] = 1;
	info->keys[2] = 1;
	info->keys[3] = 1;
	info->keys[4] = 1;
	info->keys[5] = 1;
	init_angle(info);
	info->ray.dir_perp.x = sin(info->ray.angle + PI / 2);
	info->ray.dir_perp.y = cos(info->ray.angle + PI / 2);
	info->ray.time = 0;
	info->ray.camera_orientation = 0;
	info->ray.raydir.x = 0;
	info->ray.raydir.y = 0;
	info->ray.map_x = 0;
	info->ray.in_wall = 0;
}
