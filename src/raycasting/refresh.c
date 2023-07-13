/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:00:30 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 22:19:35 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	refresh(t_info *info)
{
	mlx_destroy_image(info->mlx, info->data.img);
	move_player(info);
	info->data.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->data.img)
		free_exit(info, 1, "Malloc Error\n");
	info->data.addr = mlx_get_data_addr(info->data.img, \
		&info->data.bits_per_pixel, &info->data.line_length, &info->data.endian);
	if (!info->data.addr)
		free_exit(info, 1, "Malloc Error\n");
	raycasting(info);
	draw_minimap(info);
	draw_player(info, info->ray.angle, SIZE_MINIMAP * RADIUS, 15);
	mlx_put_image_to_window(info->mlx,
			info->mlx_win, info->data.img, 0, 0);
	return (0);
}
