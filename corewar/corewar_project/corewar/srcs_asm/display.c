/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/10 15:32:29 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_draw_display_two(t_env *e, int *x, int y)
{
	ft_printf("\n                     ");
	while ((*x) < e->off_limit[y + 1])
	{
		if (((e->tab_instruction[(*x)][0] == 1) ||
		(e->tab_instruction[(*x)][0] == 9) ||
		(e->tab_instruction[(*x)][0] == 12) ||
		(e->tab_instruction[(*x)][0] == 15)) && ((*x) == e->off_limit[y]))
		{
			ft_printf("%10i ", e->tab_instruction[(*x)][0]);
			ft_printf("%10.10s ", "");
			(*x)++;
		}
		ft_printf("%10i ", e->tab_instruction[(*x)][0]);
		(*x)++;
	}
}

static void		ft_draw_display_one(char **tmp, int nb_elem, int value)
{
	int i;

	i = 0;
	if (value == 1)
	{
		while (i < nb_elem)
		{
			ft_printf("%10.10s ", tmp[i]);
			if (i == 1)
				ft_printf("%10.10s ", "");
			i++;
		}
	}
	if (value == 3)
	{
		ft_printf("%10.10s %10.10s %10.10s ", "", tmp[0], "");
		i = 1;
		while (i < nb_elem)
		{
			ft_printf("%10.10s ", tmp[i]);
			i++;
		}
	}
}

static void		ft_calc_display(char **tmp, int nb_elem)
{
	int value;
	int value2;

	value2 = -1;
	value = ft_is_label(tmp[0]) == 1 ? -1 : 0;
	if (value != -1)
		value2 = which_op(tmp[0]);
	if (value == -1 && nb_elem > 1 && (value2 != 1) && (value2 != 9) &&
	(value2 != 12) && (value2 != 15))
		ft_draw_display_one(tmp, nb_elem, 1);
	else if (value == -1 && nb_elem == 1)
		ft_printf("%10.10s ", tmp[0]);
	else if ((value != 1) && (value != 9) && (value != 12) && (value != 15) &&
		(value >= 0))
		ft_draw_display_one(tmp, nb_elem, 3);
}

void			ft_display_offset(t_env *e)
{
	int		y;
	int		x;
	int		i;
	char	**tmp;

	y = 0;
	x = 0;
	ft_printf(LINE"%s\n\n", LINE);
	ft_printf("          %10.10s %10.10s %10.10s %10.10s %10.10s %10.10s\n\n",
	"Label", "Commande", "Octet", "Arg_1", "Arg_2", "Arg_3");
	ft_printf(LINE"%s\n\n", LINE);
	while (y < e->nb_instruction / 8)
	{
		tmp = ft_stronesplit(e->a_file[y], ' ');
		i = 0;
		while (tmp[i])
			i++;
		ft_printf("Ligne \033[36m%03i\033[0m:", y);
		ft_calc_display(tmp, i);
		ft_draw_display_two(e, &x, y);
		ft_arrdel(tmp);
		ft_printf("\n\n\n");
		y++;
	}
}
