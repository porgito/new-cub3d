/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:22:40 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 16:28:13 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	choose_texnum(t_all *all)
{
	if (all->ray.is_side_wall == 0 && all->ray.raydir.x >= 0)
		all->ray.tex_nb = 0;
	else if (all->ray.is_side_wall == 0 && all->ray.raydir.x < 0)
		all->ray.tex_nb = 1;
	else if (all->ray.is_side_wall == 1 && all->ray.raydir.y >= 0)
		all->ray.tex_nb = 2;
	else if (all->ray.is_side_wall == 1 && all->ray.raydir.y < 0)
		all->ray.tex_nb = 3;
	else
		all->ray.tex_nb = 0;
}

void	init_var_texture(t_all *all)
{
	if (all->ray.is_side_wall == 0)
		all->ray.wall_impact = all->ray.pos.y + all->ray.cam_wall_dist
			* all->ray.raydir.y;
	else
		all->ray.wall_impact = all->ray.pos.x + all->ray.cam_wall_dist
			* all->ray.raydir.x;
	all->ray.wall_impact -= floor((all->ray.wall_impact));
	all->ray.tex_x = (int)(all->ray.wall_impact * (double)64);
	if (all->ray.is_side_wall == 0 && all->ray.raydir.x > 0)
		all->ray.tex_x = 64 - all->ray.tex_x - 1;
	if (all->ray.is_side_wall == 1 && all->ray.raydir.y < 0)
		all->ray.tex_x = 64 - all->ray.tex_x - 1;
	all->ray.step_pixel = 1.0 * 64 / all->ray.line_height;
	all->ray.tex_pos = (all->ray.draw_start_tmp - HEIGHT / 2
			+ all->ray.line_height / 2) * all->ray.step_pixel;
}

void	texture(t_all *all, int x)
{
	int	y;

	choose_texnum(all);
	init_var_texture(all);
	y = all->ray.draw_start_tmp;
	while (y < all->ray.draw_end)
	{
		if (y < HEIGHT && x < WIDTH)
		{
			all->ray.tex_y = (int)all->ray.tex_pos & (64 - 1);
			all->ray.tex_pos += all->ray.step_pixel;
			all->data.addr2[y * all->data.line_length / 4 + x] = \
			all->ray.texture[all->ray.tex_nb].addr2[all->ray.tex_y \
			* 8 / 4 * all->ray.tex_x];
		}
		y++;
	}
}
