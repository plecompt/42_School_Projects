/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:10:04 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/18 18:34:17 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		test_doublons(t_list *p_a)
{
	t_list *test;

	while (p_a)
	{
		test = p_a;
		while (test)
		{
			if (test != p_a && *((int*)test->content) == *((int*)p_a->content))
				error();
			test = test->next;
		}
		p_a = p_a->next;
	}
}

t_bool		parser_arg_sup2(char **argv, t_push *list)
{
	int			i;
	long long	nb;

	i = 1;
	if (list->data->flag)
		i++;
	while (argv[i])
	{
		if (ft_str_is_only_digit(argv[i]) == ERROR)
			return (ERROR);
		nb = ft_atol(argv[i++]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ERROR);
		ft_lstadd(&(list->p_a), ft_lstnew(&nb, sizeof(int)));
	}
	if (list->p_a == NULL)
		return (ERROR);
	ft_lstreverse(&list->p_a);
	test_doublons(list->p_a);
	ELEM_A = ft_list_size(list->p_a);
	return (SUCCESS);
}

t_bool		parser_arg2(char **argv, t_push *list)
{
	int i;

	if (list->data->flag)
		i = 2;
	else
		i = 1;
	list->p_a = ft_lstatoisplit(argv[i], SPACE);
	if (list->p_a == NULL)
		return (ERROR);
	ft_lstreverse(&list->p_a);
	test_doublons(list->p_a);
	ELEM_A = ft_list_size(list->p_a);
	return (SUCCESS);
}

void		parser(int argc, char **argv, t_push *list)
{
	if (argc < 2)
		exit(0);
	if (argc == 2 || (argc == 3 && list->data->flag))
	{
		if (parser_arg2(argv, list) == ERROR)
			error();
	}
	else if (argc > 2)
	{
		if (parser_arg_sup2(argv, list) == ERROR)
			error();
	}
	register_data(list);
}
