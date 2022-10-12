/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:55:20 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 18:55:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_live(t_proc *process, t_op_arg args[3])
{
	t_cycle		*cycle;
	t_player	*player;

	process->live++;
	if ((player = find_player(args[0].value)))
	{
		cycle = &g_vm.cycle;
		cycle->last_live = player->number;
		player->last_live = cycle->count;
		player->current_live++;
		if (g_vm.option.verbose)
			ft_printf(LIVE, COUNT, process->nb, process->id);
		if (!g_vm.option.hide)
			ft_printf(STR_LIVE, -player->number, player->name);
	}
}
