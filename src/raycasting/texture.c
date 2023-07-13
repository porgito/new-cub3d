/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:22:40 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 23:55:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	choose_texnum(t_info *info)
{
	if (info->ray.is_side_wall == 0 && info->ray.raydir.x >= 0)
		info->ray.tex_nb = 0;
	else if (info->ray.is_side_wall == 0 && info->ray.raydir.x < 0)
		info->ray.tex_nb = 1;
	else if (info->ray.is_side_wall == 1 && info->ray.raydir.y >= 0)
		info->ray.tex_nb = 2;
	else if (info->ray.is_side_wall == 1 && info->ray.raydir.y < 0)
		info->ray.tex_nb = 3;
	else
		info->ray.tex_nb = 0;
}

void	init_var_texture(t_info *info)
{
	if (info->ray.is_side_wall == 0)
		info->ray.wall_impact = info->ray.pos.y + info->ray.cam_wall_dist
			* info->ray.raydir.y;
	else
		info->ray.wall_impact = info->ray.pos.x + info->ray.cam_wall_dist
			* info->ray.raydir.x;
	info->ray.wall_impact -= floor((info->ray.wall_impact));
	info->ray.tex_x = (int)(info->ray.wall_impact * (double)64);
	if (info->ray.is_side_wall == 0 && info->ray.raydir.x > 0)
		info->ray.tex_x = 64 - info->ray.tex_x - 1;
	if (info->ray.is_side_wall == 1 && info->ray.raydir.y < 0)
		info->ray.tex_x = 64 - info->ray.tex_x - 1;
	info->ray.step_pixel = 1.0 * 64 / info->ray.line_height;
	info->ray.tex_pos = (info->ray.draw_start_tmp - HEIGHT / 2
			+ info->ray.line_height / 2) * info->ray.step_pixel;
}

void	texture(t_info *info, int x)
{
	int	y;

	choose_texnum(info);
	init_var_texture(info);
	y = info->ray.draw_start_tmp;
	while (++y <= info->ray.draw_end)
	{
		info->ray.tex_y = (int)info->ray.tex_pos & (64 - 1);
		info->ray.tex_pos += info->ray.step_pixel;
		if (y < HEIGHT && x < WIDTH)
		{
			info->data.addr2[y * info->data.line_length / 4 + x] = \
			info->ray.texture[info->ray.tex_nb].addr2[info->ray.tex_y \
			* 4 / 4 * info->ray.tex_x];
		}
	}
}
