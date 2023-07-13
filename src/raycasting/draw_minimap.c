/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:42:27 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 22:19:35 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_info *info, t_vector start, int len, int color)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			my_mlx_pixel_put(&(info->data), start.x + i, start.y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_info *info)
{
	t_vector	start;
	int			x;
	int			y;

	y = info->ray.p_pos.y - RADIUS;
	if (y < 0)
		y = 0;
	while (y < info->ray.p_pos.y + RADIUS && info->pars.map[y])
	{
		x = info->ray.p_pos.x - RADIUS;
		if (x < 0)
			x = 0;
		while (x < (int)ft_strlen(info->pars.map[y])
			&& x < info->ray.p_pos.x + RADIUS && info->pars.map[y][x])
		{
			start.x = (x - info->ray.p_pos.x + RADIUS) * SIZE_MINIMAP;
			start.y = (y - info->ray.p_pos.y + RADIUS) * SIZE_MINIMAP;
			if (ft_strchr("1 ", info->pars.map[y][x]))
				draw_square(info, start, SIZE_MINIMAP, 0x00000000);
			if (ft_strchr("0NSEW", info->pars.map[y][x]))
				draw_square(info, start, SIZE_MINIMAP, 0x00EEEEE4);
			x++;
		}
		y++;
	}
}
