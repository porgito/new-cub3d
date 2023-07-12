/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:51:13 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 19:04:10 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	draw_angle(t_all *all, t_vector v1, t_vector v2, t_vector sign_diff)
{
	int	dx;
	int	dy;
	int	err;

	dx = abs((int)v2.x - (int)v1.x);
	dy = abs((int)v2.y - (int)v1.y);
	err = (dx - dy);
	while (floor(v1.x) != floor(v2.x) || floor(v1.y) != floor(v2.y))
	{
		my_mlx_pixel_put(&(all->data), v1.x, v1.y, 0x00858B8C);
		if (2 * err > -dy)
		{
			err -= dy;
			v1.x += sign_diff.x;
		}
		else if (2 * err < dx)
		{
			err += dx;
			v1.y += sign_diff.y;
		}
	}
}

void	draw_line(t_all *all, t_vector start, t_vector direction)
{
	t_vector	sign_diff;

	if (start.x < direction.x)
		sign_diff.x = 1;
	else
		sign_diff.x = -1;
	if (start.y < direction.y)
		sign_diff.y = 1;
	else
		sign_diff.y = -1;
	draw_angle(all, start, direction, sign_diff);
}

void	draw_player(t_all *all, double angle, double pos, int radius)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	int			i;

	i = 0;
	while (i < radius)
	{
		v1.x = pos + i * cos(angle);
		v1.y = pos + i * sin(angle);
		v2.x = pos + i * cos(angle + 2 * PI / 3) / 2;
		v2.y = pos + i * sin(angle + 2 * PI / 3) / 2;
		v3.x = pos + i * cos(angle + 4 * PI / 3) / 2;
		v3.y = pos + i * sin(angle + 4 * PI / 3) / 2;
		draw_line(all, v1, v2);
		draw_line(all, v2, v3);
		draw_line(all, v1, v3);
		i++;
	}
}
