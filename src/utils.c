/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:50 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

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

void	set_player_position(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (all->pars.map[y])
	{
		x = 0;
		while (all->pars.map[y][x])
		{
			if (ft_strchr("NSEW", all->pars.map[y][x]))
			{
				all->ray.p_pos.x = x + 0.5;
				all->ray.p_pos.y = y + 0.5;
				all->ray.pos.y = (double)x + 0.5;
				all->ray.pos.x = (double)y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}
