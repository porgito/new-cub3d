/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:32 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 18:40:46 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	close_win(t_all *all)
{
	free_exit(all, 0, "");
	return (0);
}

int	key_press(int keycode, t_all *all)
{
	if (keycode == ESC_KEY)
		close_win(all);
	else if (keycode == W_KEY)
		all->keys[0] = 0;
	else if (keycode == S_KEY)
		all->keys[1] = 0;
	else if (keycode == A_KEY)
		all->keys[2] = 0;
	else if (keycode == D_KEY)
		all->keys[3] = 0;
	else if (keycode == L_ARROW)
		all->keys[4] = 0;
	else if (keycode == R_ARROW)
		all->keys[5] = 0;
	return (0);
}

int	key_release(int keycode, t_all *all)
{
	if (keycode == W_KEY)
		all->keys[0] = 1;
	else if (keycode == S_KEY)
		all->keys[1] = 1;
	else if (keycode == A_KEY)
		all->keys[2] = 1;
	else if (keycode == D_KEY)
		all->keys[3] = 1;
	else if (keycode == L_ARROW)
		all->keys[4] = 1;
	else if (keycode == R_ARROW)
	{
		all->keys[5] = 1;
	}
	return (0);
}

int	ft_mouse( int x, int y, t_all *all)
{
	(void)y;
	if (x > all->mouse_pos)
	{
		all->keys[5] = 0;
		rotate_left_right(all);
		all->keys[5] = 1;
	}
	else if (x < all->mouse_pos)
	{
		all->keys[4] = 0;
		rotate_left_right(all);
		all->keys[4] = 1;
	}
	x = WIDTH / 2;
	mlx_mouse_move(all->mlx_win, WIDTH / 2, HEIGHT / 2);
	all->mouse_pos = x;
	return (0);
}
