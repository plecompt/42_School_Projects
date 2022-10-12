/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:54:30 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:41:52 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_ldi(t_proc *process, t_op_arg args[3])
{
	t_reg	*reg;
	int		a;
	int		b;
	int		offset;

	a = get_value(process, args, 0, 0);
	b = get_value(process, args, 1, 0);
	reg = get_register(process->reg, args[2].value);
	if (g_vm.reg_error)
		return ;
	offset = (a + b) % IDX_MOD;
	if (reg)
		read_on_map((char*)reg, process->pc + offset, REG_SIZE);
	if (g_vm.option.verbose)
		ft_printf(LDI, COUNT, process->nb, process->id, offset, args[2].value);
}

void		ft_lldi(t_proc *process, t_op_arg args[3])
{
	t_reg	*reg;
	int		a;
	int		b;
	int		value;

	a = get_value(process, args, 0, 0);
	b = get_value(process, args, 1, 0);
	reg = get_register(process->reg, args[2].value);
	if (g_vm.reg_error)
		return ;
	value = 0;
	if (reg)
	{
		read_on_map((char*)reg, process->pc + (a + b), REG_SIZE);
		pull_register(reg, (char*)&value);
		if (g_vm.option.verbose)
		{
			ft_printf(LLDI, COUNT, process->nb,
					process->id, (a + b), args[2].value);
		}
	}
	if (value != 0)
		process->carry = 0;
	else
		process->carry = 1;
}
