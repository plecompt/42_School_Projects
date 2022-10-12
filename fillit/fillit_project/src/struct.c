/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:45:26 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 16:45:38 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		*ft_init_struct(void)
{
	t_coord *c;

	if (!(c = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	c->link = 0;
	c->u = 3;
	c->o = 3;
	c->i = 0;
	c->j = 0;
	c->lettre = 'A';
	c->error = 0;
	c->tab = NULL;
	c->clear_tab = NULL;
	c->new_tab = NULL;
	c->tab_final_check = NULL;
	c->tab_final_parse = NULL;
	c->tab_final_transform = NULL;
	c->nb_ligne = 0;
	c->nb_trio = 0;
	c->actual_piece = 0;
	c->w = 0;
	c->x = 0;
	c->v = 0;
	c->b = 0;
	return (c);
}

void		reset(t_coord *c)
{
	c->link = 0;
	c->u = 3;
	c->o = 3;
	c->i = 0;
	c->j = 0;
	c->m = 0;
	c->w = 0;
	c->x = 0;
	c->v = 0;
	c->b = 0;
}
