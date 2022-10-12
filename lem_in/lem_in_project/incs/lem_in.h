/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:09:46 by hivian            #+#    #+#             */
/*   Updated: 2016/12/05 11:09:44 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TRUE 			1
# define FALSE 			0
# define MAX_INT 		2147483647
# define MAX  			9999
# define INF  			9999
# define WIN_WIDTH		800
# define WIN_HEIGHT		600

# include "../libft/incs/libft.h"
# include "math.h"
# include <stdio.h>

typedef struct		s_env
{
	char			**data_conv;
	char			**pipe;
	int				nb_pipe;

	int				first_ant;
	int				ants;
	int				*ants_in_room;
	int				*ants_arrived;
	int				ant_index;
	int				pos;
	int				nb_elem;
	int				i;

	int				is_start;
	int				is_end;
	int				is_pipe;
	int				room_nb;
	int				dup_start;
	int				dup_end;
	char			*start_name;
	char			*end_name;
	int				start_index;
	int				end_index;
	int				room1;
	int				room2;
	int				*cost[MAX];
	int				dist[MAX];
	int				pred[MAX];
	int				visited[MAX];
	int				min_dist;
	int				next_room;
}					t_env;

typedef struct		s_line
{
	char			*data;
	struct s_line	*next;
}					t_line;

typedef struct		s_slist
{
	t_line			*head;
}					t_slist;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	size_t			visited;
	size_t			ant_nb;
}					t_room;

void				error_handling(char *line, char *tmp, int index, t_env *e);
int					print_error(char *msg);
int					ft_isnumber(char *str);
int					ft_is_dup(t_slist *list);
long int			ft_latoi(const char *str);
t_slist				*create_list(void);
void				push_back(t_slist *list, char *data);
void				clear_list(t_slist *list);
void				print_list(t_slist *list);
void				fill_matrix(t_slist *list, t_env *e);
void				init_matrix(int **matrix, t_env *e);
void				free_matrix(int **matrix, t_env *e);
float				get_distance(int *coords);
int					get_index_from_name(t_room **r_l, char *name, t_env *e);
char				*get_name_from_index(t_room **r_l, int index, t_env *e);
void				dijkstra(int **matrix, t_room **r_l, t_slist *l, t_env *e);
void				print_all(t_room **room_list, t_slist *list, t_env *e);
void				handle_ants(t_room **r_l, int *path, t_env *e);

#endif
