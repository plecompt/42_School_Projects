/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:41:55 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 18:43:04 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		dump_cycle(char *map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < MEM_SIZE)
	{
		if (j == 64)
		{
			ft_printf("\n");
			j = 0;
			k++;
		}
		if (j == 0)
			ft_printf("%#.4p : ", k * 64);
		ft_printf("%.2x ", map[i] & 0xff);
		i++;
		j++;
	}
	ft_printf("\n");
	if (!g_vm.option.sdump)
		exit(0);
	sleep(5);
}

static void		check_live_or_dead(int *live, int *dead)
{
	int		i;

	*live = 0;
	*dead = 0;
	i = g_vm.process_count;
	while (--i >= 0)
	{
		if (g_vm.process[i].live)
			*live += g_vm.process[i].live;
		else
			*dead += 1;
	}
}

static int		check_process_live_msg(void)
{
	int		live;
	int		dead;
	int		i;

	check_live_or_dead(&live, &dead);
	if (dead > 0)
		kill_process(g_vm.process_count - dead);
	else
	{
		i = g_vm.process_count;
		while (--i >= 0)
			g_vm.process[i].live = 0;
	}
	return (live >= NBR_LIVE);
}

int				handle_cycle(t_cycle *cycle)
{
	if (cycle->count == (unsigned int)g_vm.option.dump_cycle)
		dump_cycle(g_vm.map);
	cycle->count++;
	lunch_process();
	if (cycle->count >= cycle->cycle_to_check)
	{
		cycle->count_checks += (check_process_live_msg()) ? MAX_CHECKS : 1;
		cycle->cycle_to_check = cycle->count + cycle->cycle_to_die;
	}
	if (cycle->count_checks >= MAX_CHECKS)
	{
		cycle->count_checks = 0;
		cycle->cycle_to_die -= CYCLE_DELTA;
		cycle->cycle_to_check -= CYCLE_DELTA;
	}
	if (g_vm.process_count <= 0 || cycle->cycle_to_die <= 0)
		return (0);
	return (1);
}
