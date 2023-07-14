/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:37:36 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/14 13:35:25 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_info(t_info *info, t_list *lst)
{
	info->pars.north_wall = get_lst_content(lst, "NO ");
	info->pars.south_wall = get_lst_content(lst, "SO ");
	info->pars.west_wall = get_lst_content(lst, "WE ");
	info->pars.east_wall = get_lst_content(lst, "EA ");
	info->pars.ceiling_color = parse_color(info, lst, "C ");
	info->pars.floor_color = parse_color(info, lst, "F ");
}

int	parse_parameters(t_info *info, t_list *lst)
{
	info->pars.map = lst_to_tab(lst);
	if (!info->pars.map)
		free_exit(info, 1, "Error\nMap - Invalid map\n");
	parse_info(info, lst);
	if (!info->pars.north_wall || !info->pars.south_wall
		|| !info->pars.east_wall || !info->pars.west_wall
		|| info->pars.ceiling_color == (uint32_t)-1
		|| !info->pars.map || info->pars.floor_color == (uint32_t)-1)
		return (1);
	if ((int)info->pars.ceiling_color == -2
		|| (int)info->pars.floor_color == -2)
		return (2);
	if (ft_strlen(ft_strnstr(info->pars.north_wall, ".xpm",
				ft_strlen(info->pars.north_wall))) != 4
		|| ft_strlen(ft_strnstr(info->pars.south_wall,
				".xpm", ft_strlen(info->pars.south_wall))) != 4
		|| ft_strlen(ft_strnstr(info->pars.east_wall,
				".xpm", ft_strlen(info->pars.east_wall))) != 4
		|| ft_strlen(ft_strnstr(info->pars.west_wall,
				".xpm", ft_strlen(info->pars.west_wall))) != 4)
		return (3);
	return (0);
}

void	parsing(t_info *info, char *file)
{
	int		fd;
	int		err;
	t_list	*lst;

	lst = NULL;
	fd = open(file, O_RDWR);
	if (fd < 0 || ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4
		|| ft_strchr(ft_strchr(file, '.') + 1, '.') != NULL)
		free_exit(info, 1, "Error\nCannot open map\n");
	lst = file_to_lst(lst, fd);
	if (!lst)
		free_exit(info, 1, "Malloc Error\n");
	err = parse_parameters(info, lst);
	free_lst(lst);
	if (err == 1)
		free_exit(info, 1, "Error\nMap - missing or duplicate parameter\n");
	if (err == 2)
		free_exit(info, 1, "Error\nMap - invalid color \n");
	if (err == 3)
		free_exit(info, 1, "Error\nInvalid XPM extension\n");
}
