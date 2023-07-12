/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:31:36 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 18:50:18 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void	init_textures_east_west(t_all *all)
{
	all->ray.texture[2].img = mlx_xpm_file_to_image(all->mlx, \
		all->pars.east_wall, &(all->ray.texture[2].pix_height), \
		&(all->ray.texture[2].pix_height));
	if (!all->ray.texture[2].img)
		free_exit(all, 1, "Error\nXPM Error\n");
	all->ray.texture[2].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[2].img, \
		&all->ray.texture[2].bits_per_pixel, &all->ray.texture[2].line_length, \
		&all->ray.texture[2].endian);
	all->ray.texture[3].img = mlx_xpm_file_to_image(all->mlx, \
		all->pars.west_wall, &(all->ray.texture[3].pix_height), \
		&(all->ray.texture[3].pix_height));
	if (!all->ray.texture[3].img)
		free_exit(all, 1, "Error\nXPM Error\n");
	all->ray.texture[3].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[3].img, \
		&all->ray.texture[3].bits_per_pixel, &all->ray.texture[3].line_length, \
		&all->ray.texture[3].endian);
}

void	init_textures(t_all *all)
{
	all->ray.texture[0].img = mlx_xpm_file_to_image(all->mlx, \
		all->pars.south_wall, &(all->ray.texture[0].pix_height), \
		&(all->ray.texture[0].pix_height));
	if (!all->ray.texture[0].img)
		free_exit(all, 1, "Error\nXPM Error\n");
	all->ray.texture[0].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[0].img, \
		&all->ray.texture[0].bits_per_pixel, &all->ray.texture[0].line_length, \
		&all->ray.texture[0].endian);
	all->ray.texture[1].img = mlx_xpm_file_to_image(all->mlx, \
		all->pars.north_wall, &(all->ray.texture[1].pix_height), \
		&(all->ray.texture[1].pix_height));
	if (!all->ray.texture[1].img)
		free_exit(all, 1, "Error\nXPM Error\n");
	all->ray.texture[1].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[1].img, \
		&all->ray.texture[1].bits_per_pixel, &all->ray.texture[1].line_length, \
		&all->ray.texture[1].endian);
	init_textures_east_west(all);
}
