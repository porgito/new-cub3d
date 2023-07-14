/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:04:43 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/14 13:36:12 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_raycasting(int i, t_info *info)
{
	info->ray.camera_orientation = 2 * i / (double)WIDTH - 1;
	info->ray.raydir.x = info->ray.delta_pos.y
		+ info->ray.dir_perp.x * info->ray.camera_orientation;
	info->ray.raydir.y = info->ray.delta_pos.x
		+ info->ray.dir_perp.y * info->ray.camera_orientation;
	info->ray.map_x = (int)info->ray.pos.x;
	info->ray.map_y = (int)info->ray.pos.y;
	info->ray.deltadist.x = sqrt(1
			+ (info->ray.raydir.y * info->ray.raydir.y)
			/ (info->ray.raydir.x * info->ray.raydir.x));
	info->ray.deltadist.y = sqrt(1
			+ (info->ray.raydir.x * info->ray.raydir.x)
			/ (info->ray.raydir.y * info->ray.raydir.y));
	info->ray.in_wall = 0;
}

void	raydir_raycasting(t_info *info)
{
	if (info->ray.raydir.x < 0)
	{
		info->ray.step_x = -1;
		info->ray.sidedist.x = (info->ray.pos.x
				- info->ray.map_x) * info->ray.deltadist.x;
	}
	else
	{
		info->ray.step_x = 1;
		info->ray.sidedist.x = (info->ray.map_x
				+ 1.0 - info->ray.pos.x) * info->ray.deltadist.x;
	}
	if (info->ray.raydir.y < 0)
	{
		info->ray.step_y = -1;
		info->ray.sidedist.y = (info->ray.pos.y
				- info->ray.map_y) * info->ray.deltadist.y;
	}
	else
	{
		info->ray.step_y = 1;
		info->ray.sidedist.y = (info->ray.map_y
				+ 1.0 - info->ray.pos.y) * info->ray.deltadist.y;
	}
}

void	check_hit_wall(t_info *info)
{
	while (info->ray.in_wall == 0)
	{
		if (info->ray.sidedist.x < info->ray.sidedist.y)
		{
			info->ray.sidedist.x += info->ray.deltadist.x;
			info->ray.map_x += info->ray.step_x;
			info->ray.is_side_wall = 0;
		}
		else
		{
			info->ray.sidedist.y += info->ray.deltadist.y;
			info->ray.map_y += info->ray.step_y;
			info->ray.is_side_wall = 1;
		}
		if (info->pars.map[info->ray.map_x][info->ray.map_y] == '1')
			info->ray.in_wall = 1;
	}
}

void	draw_wall(t_info *info, int i)
{
	int	d;
	int	color;

	info->ray.draw_start = -info->ray.line_height / 2 + HEIGHT / 2;
	if (info->ray.draw_start < 0)
		info->ray.draw_start = 0;
	info->ray.draw_end = info->ray.line_height / 2 + HEIGHT / 2;
	if (info->ray.draw_end >= HEIGHT)
		info->ray.draw_end = HEIGHT;
	d = 0;
	info->ray.draw_start_tmp = info->ray.draw_start;
	while (info->ray.draw_start > d)
		my_mlx_pixel_put(&(info->data), i, d++, info->pars.ceiling_color);
	color = 0x80808080;
	if (info->ray.is_side_wall == 1)
		color = 0x00A9A9A9;
	while (info->ray.draw_start < info->ray.draw_end)
		my_mlx_pixel_put(&(info->data), i, info->ray.draw_start++, color);
	d = info->ray.draw_end;
	while (d > 0 && d < HEIGHT)
		my_mlx_pixel_put(&(info->data), i, d++, info->pars.floor_color);
}

int	raycasting(t_info *info)
{
	int	i;

	i = 0;
	(void)info;
	while (i < WIDTH)
	{
		init_raycasting(i, info);
		raydir_raycasting(info);
		check_hit_wall(info);
		if (info->ray.is_side_wall == 0)
			info->ray.cam_wall_dist = fabs((info->ray.map_x - info->ray.pos.x
						+ (1 - info->ray.step_x) / 2) / info->ray.raydir.x);
		else
			info->ray.cam_wall_dist = fabs((info->ray.map_y - info->ray.pos.y
						+ (1 - info->ray.step_y) / 2) / info->ray.raydir.y);
		info->ray.line_height = (int)(HEIGHT / info->ray.cam_wall_dist);
		draw_wall(info, i);
		texture(info, i);
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->data.img, 0, 0);
	return (0);
}
