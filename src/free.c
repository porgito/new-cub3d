/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:18:10 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void	free_xpm(t_all *all)
{
	if (all->ray.texture[0].img)
		mlx_destroy_image(all->mlx, all->ray.texture[0].img);
	if (all->ray.texture[1].img)
		mlx_destroy_image(all->mlx, all->ray.texture[1].img);
	if (all->ray.texture[2].img)
		mlx_destroy_image(all->mlx, all->ray.texture[2].img);
	if (all->ray.texture[3].img)
		mlx_destroy_image(all->mlx, all->ray.texture[3].img);
}

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

void	free_pars(t_all *all)
{
	free_array(all->pars.map);
	free(all->pars.north_wall);
	free(all->pars.south_wall);
	free(all->pars.east_wall);
	free(all->pars.west_wall);
}

void	free_exit(t_all *all, int exit_code, char *error_message)
{
	free_xpm(all);
	if (all->data.img != NULL)
		mlx_destroy_image(all->mlx, all->data.img);
	if (all->mlx_win)
	{
		mlx_clear_window(all->mlx, all->mlx_win);
		mlx_destroy_window(all->mlx, all->mlx_win);
	}
	if (all->mlx)
	{
		// mlx_destroy_display(all->mlx);
		free(all->mlx);
	}
	free_pars(all);
	if (exit_code != 0)
		ft_putstr_fd(error_message, 2);
	exit(exit_code);
}
