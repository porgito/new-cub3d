/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:06:42 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 15:50:00 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	move_up_down(t_all *all, double move_speed)
{
	int	x;
	int	y;

	x = floor(all->ray.p_pos.x + (cos(all->ray.angle) / move_speed) * 4);
	y = floor(all->ray.p_pos.y + (sin(all->ray.angle) / move_speed) * 4);
	if (all->keys[0] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.x += cos(all->ray.angle) / move_speed;
		all->ray.p_pos.y += sin(all->ray.angle) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
	x = floor(all->ray.p_pos.x - (cos(all->ray.angle) / move_speed) * 4);
	y = floor(all->ray.p_pos.y - (sin(all->ray.angle) / move_speed) * 4);
	if (all->keys[1] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.x -= cos(all->ray.angle) / move_speed;
		all->ray.p_pos.y -= sin(all->ray.angle) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
}

void	move_left_right(t_all *all, double move_speed)
{
	int	x;
	int	y;

	x = floor(all->ray.p_pos.x
			+ (cos(all->ray.angle - PI / 2) / move_speed) * 4);
	y = floor(all->ray.p_pos.y
			+ (sin(all->ray.angle - PI / 2) / move_speed) * 4);
	if (all->keys[2] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.y += sin(all->ray.angle - PI / 2) / move_speed;
		all->ray.p_pos.x += cos(all->ray.angle - PI / 2) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
	x = floor(all->ray.p_pos.x
			+ (cos(all->ray.angle + PI / 2) / move_speed) * 4);
	y = floor(all->ray.p_pos.y
			+ (sin(all->ray.angle + PI / 2) / move_speed) * 4);
	if (all->keys[3] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.y += sin(all->ray.angle + PI / 2) / move_speed;
		all->ray.p_pos.x += cos(all->ray.angle + PI / 2) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
}

void	rotate_left_right(t_all *all)
{
	if (all->keys[4] == 0)
		all->ray.angle -= 0.05;
	if (all->keys[5] == 0)
		all->ray.angle += 0.05;
	all->ray.delta_pos.x = cos(all->ray.angle);
	all->ray.delta_pos.y = sin(all->ray.angle);
	all->ray.dir_perp.x = sin(all->ray.angle + PI / 2);
	all->ray.dir_perp.y = cos(all->ray.angle + PI / 2);
}

int	move_player(t_all *all)
{
	double	move_speed;

	move_speed = 20;
	if ((all->keys[0] == 0 && all->keys[2] == 0)
		|| (all->keys[0] == 0 && all->keys[3] == 0)
		|| (all->keys[1] == 0 && all->keys[2] == 0)
		|| (all->keys[1] == 0 && all->keys[3] == 0))
		move_speed *= sqrt(2);
	move_up_down(all, move_speed);
	move_left_right(all, move_speed);
	rotate_left_right(all);
	return (0);
}
