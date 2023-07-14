/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:18:10 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/14 13:24:45 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_lst(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst->content);
		free(lst);
		lst = temp;
	}
}

void	free_array(char **tab)
{
	int	i;

	i = -1;
	if (tab != NULL)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
		tab = NULL;
	}
}

void	free_pars(t_info *info)
{
	free_array(info->pars.map);
	free(info->pars.north_wall);
	free(info->pars.south_wall);
	free(info->pars.east_wall);
	free(info->pars.west_wall);
}

void	free_exit(t_info *info, int exit_code, char *error_message)
{
	if (info->data.img != NULL)
		mlx_destroy_image(info->mlx, info->data.img);
	if (info->mlx_win)
	{
		mlx_clear_window(info->mlx, info->mlx_win);
		mlx_destroy_window(info->mlx, info->mlx_win);
	}
	if (info->mlx)
		free(info->mlx);
	free_pars(info);
	if (exit_code != 0)
		ft_putstr_fd(error_message, 2);
	exit(exit_code);
}
