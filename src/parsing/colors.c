/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:38:14 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	parse_color(t_all *all, t_list *lst, char *key)
{
	int		color;
	int		nbr;
	char	*temp_color;
	char	**temp_split;
	int		i;

	i = 0;
	temp_color = get_lst_content(lst, key);
	if (!temp_color)
		return (free(temp_color), -1);
	temp_split = ft_split(temp_color, ',');
	if (!temp_split)
		free_exit(all, 1, "Malloc Error\n");
	while (i < 3)
	{
		nbr = ft_atoi(temp_split[i]);
		if (nbr > 255 || nbr < 0 || ft_strlen_array(temp_split) > 3)
			return (free_array(temp_split), free(temp_color), -2);
		i++;
	}
	color = create_trgb(0, ft_atoi(temp_split[0]),
			ft_atoi(temp_split[1]), ft_atoi(temp_split[2]));
	free_array(temp_split);
	free(temp_color);
	return (color);
}
