/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:53 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/12 16:41:21 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "typedef.h"

/* ******************************INIT**************************************** */

void	init_cub(t_all *all, char *map);
void	init_textures(t_all *all);
void	init_ray(t_all *all);
void	set_player_position(t_all *all);

/* ******************************FREE**************************************** */
void	free_exit(t_all *all, int exit_code, char *error_message);
void	free_array(char **tab);
void	free_lst(t_list *lst);

/* ******************************PARSING************************************* */

void	parsing(t_all *all, char *map);
char	*get_lst_content(t_list *lst, char *key);
t_list	*file_to_lst(t_list *lst, int fd);
char	**lst_to_tab(t_list	*lst);

int		parse_color(t_all *all, t_list *lst, char *key);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

void	check_map(t_all *all);

int		ft_strlen_array(char **str);

/* *****************************LOOP***************************************** */

void	ft_mlx(t_all *all);
int		refresh(t_all *all);

/* *****************************DRAW***************************************** */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_minimap(t_all *all);
void	draw_player(t_all *all, double angle, double pos, int radius);
void	cast_rays(t_all *all);
int		raycasting(t_all *all);

/* ****************************KEYPRESS************************************** */

int		close_win(t_all *all);
int		ft_mouse( int x, int y, t_all *all);
int		move_player(t_all *all);
int		key_release(int keycode, t_all *all);
int		key_press(int keycode, t_all *all);
void	rotate_left_right(t_all *all);

/* ****************************RAYCASTING************************************ */

void	find_pos_playeur(t_all *all);
void	texture(t_all *all, int x);

#endif
