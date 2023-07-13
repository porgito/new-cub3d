/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:06:42 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 22:19:35 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_up_down(t_info *info, double move_speed)
{
	int	x;
	int	y;

	x = floor(info->ray.p_pos.x + (cos(info->ray.angle) / move_speed) * 4);
	y = floor(info->ray.p_pos.y + (sin(info->ray.angle) / move_speed) * 4);
	if (info->keys[0] == 0 && info->pars.map[y][x] != '1')
	{
		info->ray.p_pos.x += cos(info->ray.angle) / move_speed;
		info->ray.p_pos.y += sin(info->ray.angle) / move_speed;
		info->ray.pos.y = info->ray.p_pos.x;
		info->ray.pos.x = info->ray.p_pos.y;
	}
	x = floor(info->ray.p_pos.x - (cos(info->ray.angle) / move_speed) * 4);
	y = floor(info->ray.p_pos.y - (sin(info->ray.angle) / move_speed) * 4);
	if (info->keys[1] == 0 && info->pars.map[y][x] != '1')
	{
		info->ray.p_pos.x -= cos(info->ray.angle) / move_speed;
		info->ray.p_pos.y -= sin(info->ray.angle) / move_speed;
		info->ray.pos.y = info->ray.p_pos.x;
		info->ray.pos.x = info->ray.p_pos.y;
	}
}

void	move_left_right(t_info *info, double move_speed)
{
	int	x;
	int	y;

	x = floor(info->ray.p_pos.x
			+ (cos(info->ray.angle - PI / 2) / move_speed) * 4);
	y = floor(info->ray.p_pos.y
			+ (sin(info->ray.angle - PI / 2) / move_speed) * 4);
	if (info->keys[2] == 0 && info->pars.map[y][x] != '1')
	{
		info->ray.p_pos.y += sin(info->ray.angle - PI / 2) / move_speed;
		info->ray.p_pos.x += cos(info->ray.angle - PI / 2) / move_speed;
		info->ray.pos.y = info->ray.p_pos.x;
		info->ray.pos.x = info->ray.p_pos.y;
	}
	x = floor(info->ray.p_pos.x
			+ (cos(info->ray.angle + PI / 2) / move_speed) * 4);
	y = floor(info->ray.p_pos.y
			+ (sin(info->ray.angle + PI / 2) / move_speed) * 4);
	if (info->keys[3] == 0 && info->pars.map[y][x] != '1')
	{
		info->ray.p_pos.y += sin(info->ray.angle + PI / 2) / move_speed;
		info->ray.p_pos.x += cos(info->ray.angle + PI / 2) / move_speed;
		info->ray.pos.y = info->ray.p_pos.x;
		info->ray.pos.x = info->ray.p_pos.y;
	}
}

void	rotate_left_right(t_info *info)
{
	if (info->keys[4] == 0)
		info->ray.angle -= 0.05;
	if (info->keys[5] == 0)
		info->ray.angle += 0.05;
	info->ray.delta_pos.x = cos(info->ray.angle);
	info->ray.delta_pos.y = sin(info->ray.angle);
	info->ray.dir_perp.x = sin(info->ray.angle + PI / 2);
	info->ray.dir_perp.y = cos(info->ray.angle + PI / 2);
}

int	move_player(t_info *info)
{
	double	move_speed;

	move_speed = 20;
	if ((info->keys[0] == 0 && info->keys[2] == 0)
		|| (info->keys[0] == 0 && info->keys[3] == 0)
		|| (info->keys[1] == 0 && info->keys[2] == 0)
		|| (info->keys[1] == 0 && info->keys[3] == 0))
		move_speed *= sqrt(2);
	move_up_down(info, move_speed);
	move_left_right(info, move_speed);
	rotate_left_right(info);
	return (0);
}
