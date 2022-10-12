/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 16:45:56 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/17 11:29:58 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list	t_list;
struct		s_list
{
	int		data;
	t_list *next;
};

int				croissant(int a, int b)
{
	return (a <= b);
}

void			print_list(t_list *lst)
{
	while (lst)
	{
		if (lst->next)
			printf("%d --> ", lst->data);
		else
			printf("%d\n", lst->data);
		lst = lst->next;
	}
}

t_list			*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int			i;
	t_list		*tmp;
	int			tmp2;

	i = 0;
	if (lst && cmp)
	{
		while (!i)
		{
			i = 1;
			tmp = lst;
			while (tmp->next)
			{
				if ((!cmp(tmp->data, tmp->next->data)) && (tmp->data != tmp->next->data))
				{
					i = 0;
					tmp2 = tmp->data;
					tmp->data = tmp->next->data;
					tmp->next->data = tmp2;
				}
				tmp = tmp->next;
			}
		}
	}
	return (lst);
}

int			main(void)
{
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *d;
	t_list *e;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	c = malloc(sizeof(t_list));
	d = malloc(sizeof(t_list));
	e = malloc(sizeof(t_list));
	a->data = 4;
	b->data = 2;
	c->data = 1;
	d->data = 3;
	e->data = 2;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = NULL;
	print_list(a);
	print_list(sort_list(a, &croissant));
	return (0);
}
