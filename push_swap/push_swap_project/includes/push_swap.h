/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:45 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/10 16:36:47 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <limits.h>

# define ELEM_A list->data->nb_elem_a
# define ELEM_B list->data->nb_elem_b
# define MAX_A list->data->nb_max_a
# define MAX_B list->data->nb_max_b
# define MIN_A list->data->nb_min_a
# define MIN_B list->data->nb_min_b
# define LAST_A list->data->last_a
# define LAST_B list->data->last_b
# define MAX list->data->max
# define MIN list->data->min
# define TMP *((int*)tmp->content)
# define PA *((int*)list->p_a->content)
# define PA_N *((int*)list->p_a->next->content)
# define PB *((int*)list->p_b->content)
# define PB_N *((int*)list->p_b->next->content)
# define BEG *((int*)begin->content)

typedef struct	s_data
{
	int			nb_elem_a;
	int			nb_elem_b;
	int			nb_max_a;
	int			nb_max_b;
	int			nb_min_a;
	int			nb_min_b;
	int			last_a;
	int			last_b;
	int			max;
	int			min;
	int			flag;
}				t_data;

typedef struct	s_push
{
	t_data		*data;
	t_list		*p_a;
	t_list		*p_b;
	t_list		*op;
}				t_push;

typedef enum	e_enum
{
	SUCCESS = 1,
	ERROR = 0,
	TRUE = 1,
	FALSE = 0,
	SPACE = ' ',
}				t_enum;

void			print_flag(t_push *list);
void			swap_a(t_push *list);
void			swap_b(t_push *list);
void			swap_ss(t_push *list);
void			push_b(t_push *list);
void			push_a(t_push *list);
void			rev_rotate_rr(t_push *list);
void			rev_rotate_a(t_push *list);
void			rev_rotate_b(t_push *list);
void			rotate_rr(t_push *list);
void			rotate_b(t_push *list);
void			rotate_a(t_push *list);
void			error(void);
void			print_list(t_push *list);
void			parser(int argc, char **argv, t_push *list);
void			test_doublons(t_list *p_a);
t_bool			parser_arg2(char **argv, t_push *list);
t_bool			parser_arg_sup2(char **argv, t_push *list);
void			register_data(t_push *list);
void			register_data_pb(t_push *list);
void			sort_insertion(t_push *list);
void			sort_bubble(t_push *list);
void			quick_sort(t_push *list);
int				*sort_int_tab(t_list *p_a, int size);
int				number_sup(int *tab, int size, int number);
t_bool			whos_next(int *tab, int elem, int nb, int next);
void			data_init(t_data *data, t_push *list);
t_bool			str_is_only_digit(char *str);

#endif
