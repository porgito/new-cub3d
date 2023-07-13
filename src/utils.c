/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:50 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 22:16:50 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strlen_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	set_player_position(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (info->pars.map[y])
	{
		x = 0;
		while (info->pars.map[y][x])
		{
			if (ft_strchr("NSEW", info->pars.map[y][x]))
			{
				info->ray.p_pos.x = x + 0.5;
				info->ray.p_pos.y = y + 0.5;
				info->ray.pos.y = (double)x + 0.5;
				info->ray.pos.x = (double)y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}
