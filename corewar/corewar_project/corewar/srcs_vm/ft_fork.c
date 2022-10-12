/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:53:27 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:33:27 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_fork(t_proc *process, t_op_arg args[3])
{
	t_proc		*new;
	int			offset;

	new = create_process(process->pc, process, -process->nb);
	offset = (short)args[0].value % IDX_MOD;
	go_next_op(new, offset);
	if (g_vm.option.verbose)
		ft_printf(FORK, COUNT, process->nb, process->id, "FORK", offset);
}

void		ft_lfork(t_proc *process, t_op_arg args[3])
{
	t_proc		*new;

	new = create_process(process->pc, process, -process->nb);
	go_next_op(new, (short)args[0].value);
	if (g_vm.option.verbose)
	{
		ft_printf(FORK, COUNT, process->nb, process->id,
				"LFORK", (short)args[0].value);
	}
}
