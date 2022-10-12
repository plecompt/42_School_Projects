/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:52 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 11:16:54 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <sys/time.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

# define ESC			53
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define SHIFT 			257
# define PLUS 			69
# define MINUS 			78
# define PAUSE			35
# define TROLL 			17
# define RESTORE		15
# define DEMO			259
# define TAB 			48
# define CTRL 			256
# define W				13
# define S				1
# define A				0
# define D				2

# define WIN_WIDTH		1200
# define WIN_HEIGHT		1000
# define MAP_WIDTH		24
# define MAP_HEIGHT		24
# define C 				0xFFFFFF

# define TRUE			1
# define FALSE			0

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_paint
{
	t_color			north;
	t_color			south;
	t_color			west;
	t_color			east;
}					t_paint;

typedef struct		s_input
{
	int				up;
	int				down;
	int				left;
	int				right;
}					t_input;

typedef struct		s_draw
{
	int				x;
	int				map_x;
	int				map_y;
	double			camera;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	t_color			color;
}					t_draw;

typedef struct		s_move
{
	struct timeval	time;
	long			sec;
	long			usec;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
}					t_move;

typedef struct		s_env
{
	int				**world_map;
	int				nb_wall;
	int				nb_square;
	int				nb_line;
	double			mv_speed;
	double			rt_speed;
	int				shift_key;
	int				troll_mode;
	int				pause;
	int				fps;
	int				controls;
	double			degrad_color_1;
	double			degrad_color_2;
	double			degrad_color_3;
	void			*mlx;
	void			*win;
	void			*img;
	t_paint			paint;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			frame_time;
	t_input			input;
	t_draw			draw;
	t_move			move;
}					t_env;

void				ft_init_env(t_env *e);
void				ft_init_draw(t_env *e);
void				ft_fill_paint(t_paint *paint);
void				ft_init_map(t_env *e);
void				ft_init_map_path(t_env *e, char *path);
void				ft_init_move(t_env *e);
void				ft_get_color(int red, int green, int blue, t_color *color);
void				ft_raycasting(t_env *e);
void				ft_calc_steps_and_side_dist(t_env *e);
void				ft_calc_wall_dist(t_env *e);
void				ft_calc_line_height(t_env *e);
void				ft_rotate_left(t_env *e);
void				ft_rotate_right(t_env *e);
void				ft_calculate_degrade(t_env *e);
void				ft_calculate_degrade_floor(t_env *e);
void				ft_display(t_env *e);
void				ft_reset_value(t_env *e);
void				ft_demo(t_env *e);
void				ft_key_hook_part2(int key, t_env *e);
int					key_hook(int key, t_env *e);
int					key_hook_r(int key, t_env *e);
int					loop_hook(t_env *e);
void				ft_draw_floor(t_env *e, int x, int start);
void				put_pixel_to_img(t_env *e, int x, int y, t_color *color);
#endif
