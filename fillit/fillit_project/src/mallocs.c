/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:53:08 by plecompt          #+#    #+#             */
/*   Updated: 2016/04/15 18:43:43 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_malloc_dimension(t_coord *c)
{
	int *tableau2;
	int i;

	i = 0;
	if (!(c->tab_dimension = (int **)malloc(sizeof(int *) * c->nb_trio)))
		return ;
	if (!(tableau2 = (int *)malloc(sizeof(int) * 2 * c->nb_trio)))
		return ;
	while (i < c->nb_trio)
	{
		c->tab_dimension[i] = &tableau2[i * 2];
		c->tab_dimension[i][0] = ft_longueur(c->tab_final_check[i]);
		c->tab_dimension[i][1] = ft_largeur(c->tab_final_check[i]);
		i++;
	}
}

void		ft_malloc_tab3d_check(t_coord *c)
{
	reset(c);
	c->nb_trio = c->nb_ligne / 4;
	if (!(c->tab_final_check = (char ***)malloc(sizeof(char **) * c->nb_trio)))
		return ;
	while (c->w < c->nb_trio)
	{
		if (!(c->tab_final_check[c->w] = (char **)malloc(sizeof(char *) * 4)))
			return ;
		while (c->x < 4)
		{
			if (!(c->tab_final_check[c->w][c->x] =
			(char *)malloc(sizeof(char) * 4)))
				return ;
			while (c->b < 4)
			{
				c->tab_final_check[c->w][c->x][c->b] = c->new_tab[c->v][c->b];
				c->b++;
			}
			c->b = 0;
			c->v++;
			c->x++;
		}
		c->x = 0;
		c->w++;
	}
}

void		ft_malloc_tab3d_suprem(t_coord *c)
{
	reset(c);
	if (!(c->tab_final_parse = (char ***)malloc(sizeof(char **) * c->nb_trio)))
		return ;
	while (c->w < c->nb_trio)
	{
		if (!(c->tab_final_parse[c->w] = (char **)malloc(sizeof(char *) * 4)))
			return ;
		while (c->x < 4)
		{
			if (!(c->tab_final_parse[c->w][c->x] =
			(char *)malloc(sizeof(char) * 4)))
				return ;
			while (c->b < 4)
			{
				c->tab_final_parse[c->w][c->x][c->b] = c->clear_tab[c->v];
				c->b++;
				c->v++;
			}
			c->b = 0;
			c->x++;
		}
		c->x = 0;
		c->w++;
	}
}

void		ft_malloc_tab2d(t_coord *c)
{
	reset(c);
	if (!(c->new_tab = (char **)malloc(sizeof(char *) * ft_strlen(c->tab))))
		return ;
	while (c->i < (int)ft_strlen(c->tab) - 1)
	{
		while (c->tab[c->i] == '\n' && c->tab[c->i])
		{
			c->i++;
			c->b++;
		}
		if (!(c->new_tab[c->j] = (char *)malloc(sizeof(char) *
			ft_strlen(c->tab))))
			return ;
		while (c->tab[c->i] != '\n')
		{
			c->new_tab[c->j][c->m] = c->tab[c->i];
			c->i++;
			c->m++;
		}
		ft_malloc_pre_check(c);
	}
	c->nb_ligne = c->j;
	c->nb_ligne % 4 ? ft_exit() : 0;
}

void		ft_transform(t_coord *c)
{
	reset(c);
	if (!(c->clear_tab = (char *)malloc(sizeof(char) * c->nb_ligne * 4)))
		return ;
	while (c->i < c->nb_ligne)
	{
		while (c->j < 4)
		{
			if (c->new_tab[c->i][c->j] == '#')
				c->clear_tab[c->m] = c->lettre;
			else
				c->clear_tab[c->m] = c->new_tab[c->i][c->j];
			c->j++;
			c->m++;
		}
		c->w++;
		if (c->w == 4)
		{
			c->lettre++;
			c->w = 0;
		}
		c->j = 0;
		c->i++;
	}
}
