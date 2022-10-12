/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/25 14:18:50 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		which_kind(char *str)
{
	int i;

	i = 0;
	if (is_reg(str) == 1)
		i = 1;
	if (is_direct(str) == 2)
		i = 2;
	if (is_indirect(str) == 3)
		i = 3;
	if (is_direct_label(str) == 4)
		i = 4;
	if (is_indirect_label(str) == 5)
		i = 5;
	return (i);
}

int		how_many_elem(char *tmp)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (ft_strcmp(g_op_tab[i].name, tmp) == 0)
			return (g_op_tab[i].nbr_args);
		i++;
	}
	return (-1);
}

int		which_op(char *tmp)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (ft_strcmp(g_op_tab[i].name, tmp) == 0)
			return (g_op_tab[i].op_code);
		i++;
	}
	return (-1);
}
