/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnguyen <hnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:28:45 by hnguyen           #+#    #+#             */
/*   Updated: 2016/03/31 16:41:14 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_coord
{
	int		size;
	int		u;
	int		o;
	int		link;
	int		error;
	int		i;
	int		j;
	int		m;
	char	lettre;
	char	*tab;
	char	*clear_tab;
	char	**new_tab;
	char	***tab_final_check;
	char	***tab_final_parse;
	char	***tab_final_transform;
	int		nb_ligne;
	int		nb_trio;
	int		**tab_dimension;
	int		**coordinate;
	int		w;
	int		x;
	int		v;
	int		b;
	char	**tab_algo;
	int		actual_piece;
}				t_coord;

void			ft_malloc_dimension(t_coord *c);
void			ft_malloc_tab3d_check(t_coord *c);
void			ft_malloc_tab3d_suprem(t_coord *c);
void			ft_malloc_tab2d(t_coord *c);
void			ft_transform(t_coord *c);

void			ft_malloc_pre_check(t_coord *c);
int				ft_final_check(char **tab, t_coord *c);
int				ft_tab_str_check_validity(char **tab);
int				ft_tab_str_check_content(char **tab);
void			ft_check_tab(t_coord *c);

void			ft_intrude_part3(t_coord *c, int w);
void			ft_intrude_part2(t_coord *c, int w);
void			ft_intrude(t_coord *c, int w);
void			ft_parse(t_coord *c);
void			ft_malloc_coord(t_coord *c);

int				ft_largeur(char **tab);
int				ft_longueur(char **tab);
int				ft_are_you_a_square(char **tab);
int				ft_sqrt(int aera);

void			ft_exit(void);
void			ft_i_want_to_break_free(t_coord *c);
void			ft_reset_xy_for_piece(t_coord *c, int piece);
void			ft_display_plateau(t_coord *c);

void			ft_creat_plateau(t_coord *c);
void			ft_clear_that_one(t_coord *c, int piece);
int				ft_are_you_empty(t_coord *c, int startx, int starty, int piece);
void			ft_put_that_piece_here(t_coord *c, int x, int y, int piece);
int				ft_move_to_next_one(t_coord *c, int piece);

void			ft_resolve(t_coord *c, int piece);
void			ft_algo(t_coord *c);
void			ft_starter(int fd, t_coord *c, char *argv);

void			reset(t_coord *c);
t_coord			*ft_init_struct(void);

#endif
