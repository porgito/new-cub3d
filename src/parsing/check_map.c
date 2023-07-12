/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:18:09 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

int	check_open_map(char **map, int i, int j)
{
	int	len_i;
	int	len_j;

	len_j = ft_strlen_array(map) - 1;
	len_i = ft_strlen(map[j]) - 1;
	if (ft_strchr(" 01NSEW", map[j][i]) == NULL)
		return (1);
	if (ft_strchr("0NSEW", map[j][i])
		&& (i == 0 || j == 0 || i == len_i || j == len_j))
		return (2);
	if (ft_strchr("0NSEW", map[j][i])
	&& ((j > 0 && (int)ft_strlen(map[j - 1]) - 1 < i)
	|| (j < len_j && (int)ft_strlen(map[j + 1]) - 1 < i)
	|| ((j < len_j && !ft_strchr("01NSEW", map[j + 1][i]))
	|| (j > 0 && !ft_strchr("01NSEW", map[j - 1][i]))
	|| (i < len_i && !ft_strchr("01NSEW", map[j][i + 1]))
	|| (i > 0 && !ft_strchr("01NSEW", map[j][i - 1])))))
		return (2);
	return (0);
}

int	check_map_caracters(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (check_open_map(map, i, j) != 0)
				return (check_open_map(map, i, j));
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	check_multiple_player(char **map)
{
	int	i;
	int	j;
	int	nb_player;

	i = 0;
	j = 0;
	nb_player = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (ft_strchr("NSEW", map[j][i]))
				nb_player++;
			i++;
		}
		i = 0;
		j++;
	}
	return (nb_player);
}

void	check_map(t_all *all)
{
	int	res;
	int	nb_player;

	nb_player = check_multiple_player(all->pars.map);
	if (nb_player > 1)
		free_exit(all, 1, "Error\nMap - Multiple players\n");
	if (nb_player < 1)
		free_exit(all, 1, "Error\nMap - No player\n");
	res = check_map_caracters(all->pars.map);
	if (res == 1)
		free_exit(all, 1, "Error\nMap - Invalid caracter\n");
	if (res == 2)
		free_exit(all, 1, "Error\nMap - Invalid map\n");
}
