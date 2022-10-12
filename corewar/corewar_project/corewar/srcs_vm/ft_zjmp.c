/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:59:19 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 18:59:28 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_zjmp(t_proc *process, t_op_arg args[3])
{
	if (process->carry)
	{
		go_next_op(process, (short)args[0].value % IDX_MOD);
		if (g_vm.option.verbose)
			ft_printf(ZJMP, COUNT, process->nb, process->id, args[0].value);
	}
	else
		go_next_op(process, 3);
}
