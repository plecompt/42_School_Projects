/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:01:24 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 19:02:59 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_player		*get_winner(int id)
{
	t_player	*player;
	int			i;

	i = -1;
	while (++i < g_vm.player_count)
	{
		player = &g_vm.player[i];
		if (player->number == id)
			return (player);
	}
	return (NULL);
}

static void			lunch_vm2(void)
{
	t_player	*winner;

	g_vm.cycle.cycle_to_die = CYCLE_TO_DIE;
	g_vm.cycle.cycle_to_check = CYCLE_TO_DIE;
	g_vm.cycle.count_checks = 0;
	while (handle_cycle(&g_vm.cycle))
		;
	if ((winner = get_winner(g_vm.cycle.last_live)))
		ft_printf(STR_WINNER, -winner->number, winner->name);
	else
		ft_printf(STR_WINNER, -g_vm.player->number, g_vm.player->name);
}

void				lunch_vm(void)
{
	int			i;
	int			start;
	t_player	*player;
	char		map[MEM_SIZE];

	ft_printf("Introducing contestants...\n");
	i = -1;
	player = g_vm.player;
	g_vm.map = &map[0];
	ft_bzero(map, MEM_SIZE);
	while (++i < g_vm.player_count)
	{
		ft_printf(STR_PLAYER, player[i].number, (int)player[i].prog_size,
				player[i].name, player[i].comment);
		player[i].number = -player[i].number;
		g_vm.sound[i] = player[i].number;
		start = (MEM_SIZE / g_vm.player_count) * i;
		ft_memcpy(&map[start], player[i].bytecode, player[i].prog_size);
		player[i].pc = &map[start];
		create_process(player[i].pc, NULL, player[i].number);
	}
	lunch_vm2();
}
