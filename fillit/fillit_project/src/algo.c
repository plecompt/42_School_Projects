/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_creat_plateau(t_coord *c)
{
	int i;

	i = 0;
	if (!(c->tab_algo = (char **)malloc(sizeof(char *) * 26)))
		return ;
	while (i < 26)
	{
		c->tab_algo[i] = ".";
		while (ft_strlen(c->tab_algo[i]) < 26)
			c->tab_algo[i] = ft_strjoin(c->tab_algo[i], ".");
		i++;
	}
}

void		ft_clear_that_one(t_coord *c, int piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < c->size)
	{
		while (j < c->size)
		{
			if (c->tab_algo[i][j] == 'A' + piece - 1)
				c->tab_algo[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

int			ft_are_you_empty(t_coord *c, int startx, int starty, int piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < c->w)
	{
		while (j < c->x)
		{
			if (c->tab_algo[starty + i][startx + j] == '.' ||
				c->tab_final_transform[piece - 1][i][j] == '.' ||
				c->tab_algo[starty + i][startx + j] == 'A' + piece - 1)
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

void		ft_put_that_piece_here(t_coord *c, int x, int y, int piece)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (c->w - i)
	{
		while (c->x - j)
		{
			if (c->tab_algo[y + i][x + j] == '.')
				c->tab_algo[y + i][x + j] =
			c->tab_final_transform[piece - 1][i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

int			ft_move_to_next_one(t_coord *c, int piece)
{
	reset(c);
	c->w = c->tab_dimension[piece - 1][0];
	c->x = c->tab_dimension[piece - 1][1];
	while (c->coordinate[piece - 1][1] <= c->size - c->w)
	{
		while (c->coordinate[piece - 1][0] <= c->size - c->x)
		{
			if (ft_are_you_empty(c, c->coordinate[piece - 1][0],
			c->coordinate[piece - 1][1], piece) == 1)
			{
				ft_put_that_piece_here(c, c->coordinate[piece - 1][0],
				c->coordinate[piece - 1][1], piece);
				c->coordinate[piece - 1][0]++;
				return (1);
			}
			c->coordinate[piece - 1][0]++;
		}
		c->coordinate[piece - 1][0] = 0;
		c->coordinate[piece - 1][1]++;
	}
	return (0);
}
