/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:12:47 by jlaurent          #+#    #+#             */
/*   Updated: 2023/07/14 14:22:38 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define SIZE_MINIMAP 25
# define RADIUS 5
# define HEIGHT 1080
# define WIDTH 1920
# define PI 3.141592653589793

# ifdef __APPLE__
#  define FORWARD 13
#  define LEFT 0
#  define BACK 1
#  define RIGHT 2
#  define VIEW_LEFT 123
#  define VIEW_RIGHT 124
#  define ESC_KEY 53
#  define SPACE_KEY 49
# else
#  define FORWARD 119
#  define LEFT 97
#  define BACK 115
#  define RIGHT 100
#  define VIEW_LEFT 65361
#  define VIEW_RIGHT 65363
#  define ESC_KEY 65307
#  define SPACE_KEY 32

# endif

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		*addr2;
	int		bits_per_pixel;
	int		line_l;
	int		endian;
	int		pix_height;
	int		pix_wight;
}				t_data;

typedef struct s_pars
{
	char		*north_wall;
	char		*south_wall;
	char		*east_wall;
	char		*west_wall;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	char		**map;
}	t_pars;

typedef struct s_ray
{
	t_vector	p_pos;
	t_vector	delta_pos;
	double		angle;
	t_vector	pos;
	t_vector	dir;
	t_vector	dir_perp;
	double		time;
	double		camera_orientation;
	t_vector	raydir;
	t_vector	sidedist;
	t_vector	deltadist;
	int			map_x;
	int			map_y;
	double		cam_wall_dist;
	int			step_x;
	int			step_y;
	int			in_wall;
	int			is_side_wall;
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			tex_nb;
	double		wall_impact;
	int			tex_x;
	double		step_pixel;
	double		tex_pos;
	int			tex_y;
	t_data		texture[4];
	int			draw_start_tmp;
}				t_ray;

typedef struct s_info
{
	t_data		data;
	t_ray		ray;		
	t_pars		pars;
	void		*mlx;
	void		*mlx_win;
	int			mouse_pos;
	int			keys[6];
}	t_info;

#endif