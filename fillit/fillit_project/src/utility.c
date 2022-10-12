/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:14 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:15 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_display_plateau(t_coord *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < c->size)
	{
		while (j < c->size)
		{
			ft_putchar(c->tab_algo[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

void	ft_reset_xy_for_piece(t_coord *c, int piece)
{
	c->coordinate[piece - 1][1] = 0;
	c->coordinate[piece - 1][0] = 0;
}

void	ft_i_want_to_break_free(t_coord *c)
{
	free(c->new_tab);
	free(c->tab_final_check);
}
