/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:04:43 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 19:06:45 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	init_raycasting(int i, t_all *all)
{
	all->ray.camera_orientation = 2 * i / (double)WIDTH - 1;
	all->ray.raydir.x = all->ray.delta_pos.y
		+ all->ray.dir_perp.x * all->ray.camera_orientation;
	all->ray.raydir.y = all->ray.delta_pos.x
		+ all->ray.dir_perp.y * all->ray.camera_orientation;
	all->ray.map_x = (int)all->ray.pos.x;
	all->ray.map_y = (int)all->ray.pos.y;
	all->ray.deltadist.x = sqrt(1
			+ (all->ray.raydir.y * all->ray.raydir.y)
			/ (all->ray.raydir.x * all->ray.raydir.x));
	all->ray.deltadist.y = sqrt(1
			+ (all->ray.raydir.x * all->ray.raydir.x)
			/ (all->ray.raydir.y * all->ray.raydir.y));
	all->ray.in_wall = 0;
}

void	raydir_raycasting(t_all *all)
{
	if (all->ray.raydir.x < 0)
	{
		all->ray.step_x = -1;
		all->ray.sidedist.x = (all->ray.pos.x
				- all->ray.map_x) * all->ray.deltadist.x;
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.sidedist.x = (all->ray.map_x
				+ 1.0 - all->ray.pos.x) * all->ray.deltadist.x;
	}
	if (all->ray.raydir.y < 0)
	{
		all->ray.step_y = -1;
		all->ray.sidedist.y = (all->ray.pos.y
				- all->ray.map_y) * all->ray.deltadist.y;
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.sidedist.y = (all->ray.map_y
				+ 1.0 - all->ray.pos.y) * all->ray.deltadist.y;
	}
}

void	check_hit_wall(t_all *all)
{
	while (all->ray.in_wall == 0)
	{
		if (all->ray.sidedist.x < all->ray.sidedist.y)
		{
			all->ray.sidedist.x += all->ray.deltadist.x;
			all->ray.map_x += all->ray.step_x;
			all->ray.is_side_wall = 0;
		}
		else
		{
			all->ray.sidedist.y += all->ray.deltadist.y;
			all->ray.map_y += all->ray.step_y;
			all->ray.is_side_wall = 1;
		}
		if (all->pars.map[all->ray.map_x][all->ray.map_y] == '1')
			all->ray.in_wall = 1;
	}
}

void	draw_wall(t_all *all, int i)
{
	int	d;
	int	color;

	all->ray.draw_start = -all->ray.line_height / 2 + HEIGHT / 2;
	if (all->ray.draw_start < 0)
		all->ray.draw_start = 0;
	all->ray.draw_end = all->ray.line_height / 2 + HEIGHT / 2;
	if (all->ray.draw_end >= HEIGHT)
		all->ray.draw_end = HEIGHT;
	d = 0;
	all->ray.draw_start_tmp = all->ray.draw_start;
	/////////////////////////////////////////plafond
	while (all->ray.draw_start > d)
		my_mlx_pixel_put(&(all->data), i, d++, all->pars.ceiling_color);
	color = 0x80808080;
	if (all->ray.is_side_wall == 1)
		color = 0x00A9A9A9;
	while (all->ray.draw_start < all->ray.draw_end)
		my_mlx_pixel_put(&(all->data), i, all->ray.draw_start++, color);
	d = all->ray.draw_end;
	while (d > 0 && d < HEIGHT)
		my_mlx_pixel_put(&(all->data), i, d++, all->pars.floor_color);
}

int	raycasting(t_all *all)
{
	int	i;

	i = 0;
	(void)all;
	while (i < WIDTH)
	{
		init_raycasting(i, all);
		raydir_raycasting(all);
		check_hit_wall(all);
		if (all->ray.is_side_wall == 0)
			all->ray.cam_wall_dist = fabs((all->ray.map_x - all->ray.pos.x
						+ (1 - all->ray.step_x) / 2) / all->ray.raydir.x);
		else
			all->ray.cam_wall_dist = fabs((all->ray.map_y - all->ray.pos.y
						+ (1 - all->ray.step_y) / 2) / all->ray.raydir.y);
		all->ray.line_height = (int)(HEIGHT / all->ray.cam_wall_dist);
		draw_wall(all, i);
		texture(all, i);
		i++;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->data.img, 0, 0);
	return (0);
}