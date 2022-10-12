/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:56:12 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:35:51 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_st(t_proc *proc, t_op_arg args[3])
{
	t_reg	*reg_dst;

	if (args[1].type == T_IND)
	{
		if ((reg_dst = get_register(proc->reg, args[0].value)))
			write_on_map((char*)reg_dst, proc->pc +
				((short)args[1].value) % IDX_MOD, REG_SIZE);
		if (g_vm.option.verbose)
		{
			ft_printf(ST, COUNT, proc->nb, proc->id,
					args[0].value, (short)args[1].value);
		}
	}
	else if (args[1].type == T_REG)
	{
		copy_register(get_register(proc->reg, args[1].value),
					get_register(proc->reg, args[0].value));
		if (g_vm.option.verbose)
		{
			ft_printf(ST2, COUNT, proc->nb, proc->id,
					args[0].value, args[1].value);
		}
	}
}

void		ft_sti(t_proc *process, t_op_arg args[3])
{
	t_reg	*reg;
	int		offset;
	int		a;
	int		b;

	reg = get_register(process->reg, args[0].value);
	a = get_value(process, args, 1, 0);
	b = get_value(process, args, 2, 0);
	if (g_vm.reg_error)
		return ;
	offset = (a + b) % IDX_MOD;
	if (reg)
	{
		write_on_map((char*)reg, process->pc + offset, REG_SIZE);
		if (g_vm.option.verbose)
		{
			ft_printf(STI, COUNT, process->nb, process->id,
					args[0].value, offset);
		}
	}
}
