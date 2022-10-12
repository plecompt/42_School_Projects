/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 17:03:40 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/04 16:27:15 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# define BUFF_SIZE 65
# define WIDTH 1280
# define LENGTH 1920

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				nb;
	float			height;
	float			move_verti;
	float			move_hori;
	char			**av;
	int				*len_s;
	int				nb_lines_save;
	int				**tab_int_save;
	float			zoom_x;
	float			zoom_y;
	int				color_mod;
	int				color;
}					t_env;

typedef struct		s_position
{
	int				x;
	int				y;
}					t_pos;

int					ft_getnbr(char *str);
int					get_next_line(int const fd, char **line);
int					expose_hook(t_env *e);
int					hey_hook(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
void				horizontal(t_pos a, t_pos b, t_env *e, int c);
void				vertical(t_pos a, t_pos b, t_env *e, int c);
void				print(t_pos *pos, t_env *e);
void				ft_final_tab(char **tab, int nb_lines, t_env *e);
void				print_fdf(t_env e);
void				ft_read(t_env *e);
void				convert_to_int(char ***tab, int nb_lines, t_env *e);
int					couleur(t_env *e, double t);
#endif
