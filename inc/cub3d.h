/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:53 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/13 22:10:03 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include "typedef.h"

void	init_cub(t_info *info, char *map);
void	init_textures(t_info *info);
void	init_ray(t_info *info);
void	set_player_position(t_info *info);

void	free_exit(t_info *info, int exit_code, char *error_message);
void	free_array(char **tab);
void	free_lst(t_list *lst);

void	parsing(t_info *info, char *map);
char	*get_lst_content(t_list *lst, char *key);
t_list	*file_to_lst(t_list *lst, int fd);
char	**lst_to_tab(t_list	*lst);

int		parse_color(t_info *info, t_list *lst, char *key);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

void	check_map(t_info *info);

int		ft_strlen_array(char **str);

void	ft_mlx(t_info *info);
int		refresh(t_info *info);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_minimap(t_info *info);
void	draw_player(t_info *info, double angle, double pos, int radius);
int		raycasting(t_info *info);
void	texture(t_info *info, int x);

int		close_win(t_info *info);
int		mouse_hook( int x, int y, t_info *info);
int		move_player(t_info *info);
int		key_release(int keycode, t_info *info);
int		key_press(int keycode, t_info *info);
void	rotate_left_right(t_info *info);

#endif