/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forced_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:10:11 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/05 17:11:01 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		check_number_exist(int *n, t_player *player)
{
	int		i;

	i = -1;
	while (++i < g_vm.player_count)
	{
		if (*n == player[i].number)
		{
			*n += 1;
			i = -1;
		}
	}
	if (*n < 5)
		return (1);
	return (0);
}

static void		rigth_number(t_player *player)
{
	int			i;
	int			j;
	int			number;

	i = g_vm.player_count;
	number = 1;
	while (--i >= 0)
	{
		if (player[i].forced_number == 0)
		{
			j = g_vm.player_count;
			while (--j >= 0)
			{
				if (i != j && player[i].number == player[j].number)
				{
					if (check_number_exist(&number, player))
						player[i].number = number;
					else
						player[i].number = player[j].number + 1;
				}
			}
		}
	}
}

void			swap_position(t_player *player)
{
	t_player	x;
	int			i;
	int			j;

	rigth_number(player);
	i = -1;
	while (++i < g_vm.player_count)
	{
		j = -1;
		while (++j < g_vm.player_count)
		{
			if (player[i].number < player[j].number)
			{
				x = player[i];
				player[i] = player[j];
				player[j] = x;
			}
		}
	}
}
