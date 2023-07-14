/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:31:36 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/14 13:30:21 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_textures_east_west(t_info *info)
{
	info->ray.texture[2].img = mlx_xpm_file_to_image(info->mlx, \
		info->pars.east_wall, &(info->ray.texture[2].pix_height), \
		&(info->ray.texture[2].pix_height));
	if (!info->ray.texture[2].img)
		free_exit(info, 1, "Error\nXPM Error\n");
	info->ray.texture[2].addr2 = \
		(int *)mlx_get_data_addr(info->ray.texture[2].img, \
		&info->ray.texture[2].bits_per_pixel, &info->ray.texture[2].line_l, \
		&info->ray.texture[2].endian);
	info->ray.texture[3].img = mlx_xpm_file_to_image(info->mlx, \
		info->pars.west_wall, &(info->ray.texture[3].pix_height), \
		&(info->ray.texture[3].pix_height));
	if (!info->ray.texture[3].img)
		free_exit(info, 1, "Error\nXPM Error\n");
	info->ray.texture[3].addr2 = \
		(int *)mlx_get_data_addr(info->ray.texture[3].img, \
		&info->ray.texture[3].bits_per_pixel, &info->ray.texture[3].line_l, \
		&info->ray.texture[3].endian);
}

void	init_textures(t_info *info)
{
	info->ray.texture[0].img = mlx_xpm_file_to_image(info->mlx, \
		info->pars.south_wall, &(info->ray.texture[0].pix_height), \
		&(info->ray.texture[0].pix_height));
	if (!info->ray.texture[0].img)
		free_exit(info, 1, "Error\nXPM Error\n");
	info->ray.texture[0].addr2 = \
		(int *)mlx_get_data_addr(info->ray.texture[0].img, \
		&info->ray.texture[0].bits_per_pixel, &info->ray.texture[0].line_l, \
		&info->ray.texture[0].endian);
	info->ray.texture[1].img = mlx_xpm_file_to_image(info->mlx, \
		info->pars.north_wall, &(info->ray.texture[1].pix_height), \
		&(info->ray.texture[1].pix_height));
	if (!info->ray.texture[1].img)
		free_exit(info, 1, "Error\nXPM Error\n");
	info->ray.texture[1].addr2 = \
		(int *)mlx_get_data_addr(info->ray.texture[1].img, \
		&info->ray.texture[1].bits_per_pixel, &info->ray.texture[1].line_l, \
		&info->ray.texture[1].endian);
	init_textures_east_west(info);
}
