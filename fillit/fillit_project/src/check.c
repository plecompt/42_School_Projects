/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:51:00 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 13:51:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_malloc_pre_check(t_coord *c)
{
	c->x++;
	if (!(c->x % 4) && c->tab[c->i + 1] != '\n' &&
		ft_strlen(c->tab) != 20 && c->tab[c->i + 1] != '\0')
		ft_exit();
	c->m % 4 ? ft_exit() : 0;
	c->b > 2 ? ft_exit() : 0;
	c->new_tab[c->j][c->m] = '\0';
	c->j++;
	c->m = 0;
	c->b = 0;
}

int		ft_final_check(char **tab, t_coord *c)
{
	reset(c);
	while (c->u >= 0)
	{
		while (c->o >= 0)
		{
			if (tab[c->u][c->o] == '#' && c->o != 0 && c->u != 0)
			{
				tab[c->u][c->o - 1] == '#' ? c->link++ : 0;
				tab[c->u - 1][c->o] == '#' ? c->link++ : 0;
			}
			if (tab[c->u][c->o] == '#' && c->o == 0 && c->u != 0)
				tab[c->u - 1][c->o] == '#' ? c->link++ : 0;
			if (tab[c->u][c->o] == '#' && c->u == 0)
				tab[c->u][c->o - 1] == '#' ? c->link++ : 0;
			c->o--;
		}
		c->o = 3;
		c->u--;
	}
	return (c->link >= 3 ? 1 : 0);
}

int		ft_tab_str_check_validity(char **tab)
{
	int i;
	int diez;
	int point;
	int j;

	i = 0;
	diez = 0;
	point = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			tab[i][j] == '#' ? diez++ : 0;
			tab[i][j] == '.' ? point++ : 0;
			j++;
		}
		i++;
		j = 0;
	}
	if (diez == 4 && point == 12)
		return (1);
	return (0);
}

int		ft_tab_str_check_content(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] != '.' && tab[i][j] != '#')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	ft_check_tab(t_coord *c)
{
	int i;

	i = 0;
	while (i < c->nb_trio)
	{
		ft_tab_str_check_content(c->tab_final_check[i]) == 1 ? 0 : c->error++;
		ft_tab_str_check_validity(c->tab_final_check[i]) == 1 ? 0 : c->error++;
		ft_final_check(c->tab_final_check[i], c) == 1 ? 0 : c->error++;
		i++;
		if (c->error > 0)
		{
			ft_putstr("error\n");
			exit(0);
		}
	}
}
