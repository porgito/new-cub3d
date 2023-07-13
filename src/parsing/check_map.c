/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:18:09 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 23:16:21 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

int	check_map_characters(char **map)
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

int	check_spawn(char **map)
{
	int	i;
	int	j;
	int	nb_spawn;

	i = 0;
	j = 0;
	nb_spawn = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (ft_strchr("NSEW", map[j][i]))
				nb_spawn++;
			i++;
		}
		i = 0;
		j++;
	}
	return (nb_spawn);
}

void	check_map(t_info *info)
{
	int	res;
	int	nb_spawn;

	nb_spawn = check_spawn(info->pars.map);
	if (nb_spawn > 1)
		free_exit(info, 1, "Error\nMap - Multiple spawns\n");
	if (nb_spawn < 1)
		free_exit(info, 1, "Error\nMap - No spawn\n");
	res = check_map_characters(info->pars.map);
	if (res == 1)
		free_exit(info, 1, "Error\nMap - Invalid character\n");
	if (res == 2)
		free_exit(info, 1, "Error\nMap - Invalid map\n");
}
