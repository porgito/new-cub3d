/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:47 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 23:27:54 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		init_cub(&info, argv[1]);
		init_ray(&info);
		ft_mlx(&info);
		free_exit(&info, 0, "");
	}
	else
		printf("Error Incorrect number of argument\n");
	return (0);
}

void	ft_mlx(t_info *info)
{
	mlx_hook(info->mlx_win, 17, 1L << 17, close_win, info);
	mlx_hook(info->mlx_win, 2, (1L << 0), key_press, info);
	mlx_hook(info->mlx_win, 3, (1L << 1), key_release, info);
	mlx_hook(info->mlx_win, 6, (1L << 6), mouse_hook, info);
	mlx_loop_hook(info->mlx, refresh, info);
	mlx_loop(info->mlx);
}

