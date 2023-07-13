/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:32 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 22:16:50 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_win(t_info *info)
{
	free_exit(info, 0, "");
	return (0);
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == ESC_KEY)
		close_win(info);
	else if (keycode == FORWARD)
		info->keys[0] = 0;
	else if (keycode == BACK)
		info->keys[1] = 0;
	else if (keycode == LEFT)
		info->keys[2] = 0;
	else if (keycode == RIGHT)
		info->keys[3] = 0;
	else if (keycode == VIEW_LEFT)
		info->keys[4] = 0;
	else if (keycode == VIEW_RIGHT)
		info->keys[5] = 0;
	return (0);
}

int	key_release(int keycode, t_info *info)
{
	if (keycode == FORWARD)
		info->keys[0] = 1;
	else if (keycode == BACK)
		info->keys[1] = 1;
	else if (keycode == LEFT)
		info->keys[2] = 1;
	else if (keycode == RIGHT)
		info->keys[3] = 1;
	else if (keycode == VIEW_LEFT)
		info->keys[4] = 1;
	else if (keycode == VIEW_RIGHT)
		info->keys[5] = 1;
	return (0);
}

int	mouse_hook( int x, int y, t_info *info)
{
	(void)y;
	if (x > info->mouse_pos)
	{
		info->keys[5] = 0;
		rotate_left_right(info);
		info->keys[5] = 1;
	}
	else if (x < info->mouse_pos)
	{
		info->keys[4] = 0;
		rotate_left_right(info);
		info->keys[4] = 1;
	}
	x = WIDTH / 2;
	mlx_mouse_move(info->mlx_win, WIDTH / 2, HEIGHT / 2);
	info->mouse_pos = x;
	return (0);
}
