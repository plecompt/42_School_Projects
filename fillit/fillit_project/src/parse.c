/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:06 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 16:25:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_intrude_part3(t_coord *c, int w)
{
	while (c->u >= 0)
	{
		while (c->tab_final_parse[w][c->u][c->o] == '.' && c->o > 0)
			c->o--;
		if (c->tab_final_parse[w][c->u][c->o] != '.')
		{
			c->u >= c->m ? c->m = c->u : 0;
			c->o >= c->x ? c->x = c->o : 0;
		}
		c->u--;
		c->o = 3;
	}
}

void		ft_intrude_part2(t_coord *c, int w)
{
	c->v = 3;
	c->b = 3;
	while (c->i <= 3)
	{
		while (c->tab_final_parse[w][c->i][c->j] == '.' && c->j < 3)
			c->j++;
		if (c->tab_final_parse[w][c->i][c->j] != '.')
		{
			c->i <= c->v ? c->v = c->i : 0;
			c->j <= c->b ? c->b = c->j : 0;
		}
		c->i++;
		c->j = 0;
	}
}

void		ft_intrude(t_coord *c, int w)
{
	int backup;
	int j;
	int i;

	i = 0;
	j = 0;
	reset(c);
	ft_intrude_part2(c, w);
	ft_intrude_part3(c, w);
	backup = c->b;
	while (c->v <= c->m)
	{
		while (c->b <= c->x)
		{
			c->tab_final_transform[w][i][j] = c->tab_final_parse[w][c->v][c->b];
			j++;
			c->b++;
		}
		c->tab_final_transform[w][i][j] = '\0';
		j = 0;
		i++;
		c->b = backup;
		c->v++;
	}
}

void		ft_parse(t_coord *c)
{
	int w;
	int x;

	w = 0;
	x = 0;
	reset(c);
	if (!(c->tab_final_transform =
				(char ***)malloc(sizeof(char **) * c->nb_trio)))
		return ;
	while (w < c->nb_trio)
	{
		if (!(c->tab_final_transform[w] =
		(char **)malloc(sizeof(char *) * c->tab_dimension[w][0])))
			return ;
		while (x <= c->tab_dimension[w][0])
		{
			if (!(c->tab_final_transform[w][x] =
				(char *)malloc(sizeof(char) * c->tab_dimension[w][1])))
				return ;
			x++;
		}
		ft_intrude(c, w);
		x = 0;
		w++;
	}
}

void		ft_malloc_coord(t_coord *c)
{
	int i;

	reset(c);
	i = 0;
	if (!(c->coordinate = (int **)malloc(sizeof(int *) * c->nb_trio)))
		return ;
	while (i < c->nb_trio)
	{
		if (!(c->coordinate[i] = (int *)malloc(sizeof(int) * 10)))
			return ;
		c->coordinate[i][0] = 0;
		c->coordinate[i][1] = 0;
		i++;
	}
}
