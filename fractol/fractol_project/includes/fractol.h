/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:03:40 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/04 16:27:15 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# define BUFF_SIZE 65
# define JULIA_WIDTH 600
# define JULIA_HEIGHT 600
# define MANBROT_WIDTH 800
# define MANBROT_HEIGHT 800
# define TREE_WIDTH 1200
# define TREE_HEIGHT 1200

typedef struct s_color	t_color;
typedef struct s_pos	t_pos;

struct			s_color
{
	int			x_julia;
	int			y_julia;
	int			red_julia;
	int			green_julia;
	int			blue_julia;

	int			x_mandelbrot;
	int			y_mandelbrot;
	int			red_m;
	int			green_m;
	int			blue_m;

};

struct			s_pos
{
	double		zoom_julia;
	double		zoom_m;
	double		zoom_tree;
	double		x_julia;
	double		y_julia;
	double		move_x_julia;
	double		move_y_julia;
	double		x_mandelbrot;
	double		y_mandelbrot;
	double		move_x_mandelbrot;
	double		move_y_mandelbrot;
	double		x_tree;
	double		y_tree;
	double		move_x_tree;
	double		move_y_tree;
};

typedef struct	s_env
{
	void		*mlx;
	void		*win_julia;
	void		*win_mandelbrot;
	void		*win_tree;
	void		*img_julia;
	void		*img_mandelbrot;
	void		*img_tree;

	char		**list_arg;
	int			julia;
	int			mandelbrot;
	int			tree;
	int			res_mandel;
	int			res_julia;

	int			julia_is_destroyed;
	int			mandelbrot_is_destroyed;
	int			tree_is_destroyed;
	int			number_of_fractal_still_alive;

	int			red_tree;
	int			green_tree;
	int			blue_tree;
	int			start_x_tree;
	int			start_y_tree;
	int			stop_time_tree;
	double		angle_tree;
	double		angle_start;
	int			nbr_branch;
	int			nb_branch_total;
	int			density;
	int			nb_of_pixel;
	int			display_debug;
	double		value;
	int			size_grow;

	int			nb_branch_draw;
	int			draw;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;

	int			handle_red_mandelbrot;
	int			handle_green_mandelbrot;
	int			handle_blue_mandelbrot;
	int			max_iter_mandelbrot;
	int			stop_time_mandelbrot;

	int			handle_red_julia;
	int			handle_green_julia;
	int			handle_blue_julia;
	int			max_iter_julia;
	int			stop_time_julia;
	t_pos		pos;
	t_color		color;
}				t_env;

void			ft_exit(int error_number);
void			ft_init_mlx(t_env *env);
void			ft_init_env(t_env *env);
void			ft_set_color(int width, int height, int resul, t_env *env);
void			ft_run(t_env *env);

void			ft_calc_julia(t_env *env);
int				ft_julia_set_position(int width, int height, t_env *env);
void			ft_set_color_jul(int width, int height, int result, t_env *env);
void			env_change_julia(int key, t_env *env);
int				key_hook_julia(int keycode, t_env *env);
int				mouse_hook_julia(int key, int x, int y, t_env *env);
int				move_hook_julia(int x, int y, t_env *e);
void			ft_init_env_for_julia(t_env *env);

void			ft_calc_mandelbrot(t_env *env);
int				ft_mandelbrot_set_position(int width, int height, t_env *e);
void			ft_set_color_m(int width, int height, int result, t_env *env);
void			env_change_mandelbrot(int key, t_env *env);
int				key_hook_mandelbrot(int keycode, t_env *env);
int				mouse_hook_mandelbrot(int key, int x, int y, t_env *env);
void			ft_init_env_for_mandelbrot(t_env *env);

void			ft_calc_tree(t_env *env, int *tab, double angle, int nb_brch);
void			ft_display_debug_tree(t_env *env);
void			env_change_tree(int key, t_env *env);
int				key_hook_tree(int keycode, t_env *env);
int				mouse_hook_tree(int key, int x, int y, t_env *e);
int				move_hook_tree(int x, int y, t_env *env);
void			ft_init_env_for_tree(t_env *env);
#endif
