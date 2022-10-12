/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:53:57 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:34:28 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_ld(t_proc *process, t_op_arg args[3])
{
	int		value;

	value = get_value(process, args, 0, 0);
	push_register(get_register(process->reg, args[1].value), (char*)&value);
	if (g_vm.reg_error)
		return ;
	if (g_vm.option.verbose)
	{
		ft_printf(ADD, COUNT, process->nb, process->id,
				"LD", value, args[1].value);
	}
	if (value != 0)
		process->carry = 0;
	else
		process->carry = 1;
}

void		ft_lld(t_proc *process, t_op_arg args[3])
{
	int		value;

	value = get_value(process, args, 0, 1);
	push_register(get_register(process->reg, args[1].value), (char*)&value);
	if (g_vm.reg_error)
		return ;
	if (g_vm.option.verbose)
		ft_printf(LLD, COUNT, process->nb, process->id, value, args[1].value);
	if (value != 0)
		process->carry = 0;
	else
		process->carry = 1;
}
