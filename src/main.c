/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:47 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 19:00:47 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc == 2)
	{
		init_cub(&all, argv[1]);
		init_ray(&all);
		ft_mlx(&all);
		free_exit(&all, 0, "");
	}
	else
		printf("Error Incorrect number of argument\n");
	return (0);
}

void	ft_mlx(t_all *all)
{
	mlx_hook(all->mlx_win, 17, 1L << 17, close_win, all);
	mlx_hook(all->mlx_win, 2, (1L << 0), key_press, all);
	mlx_hook(all->mlx_win, 3, (1L << 1), key_release, all);
	mlx_hook(all->mlx_win, 6, (1L << 6), ft_mouse, all);
	mlx_loop_hook(all->mlx, refresh, all);
	mlx_loop(all->mlx);
}

