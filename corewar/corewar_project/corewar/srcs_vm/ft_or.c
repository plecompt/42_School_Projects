/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:55:49 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:34:21 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_or(t_proc *process, t_op_arg args[3])
{
	int		a;
	int		b;
	int		or;
	t_reg	*reg;

	reg = get_register(process->reg, args[2].value);
	a = get_value(process, args, 0, 0);
	b = get_value(process, args, 1, 0);
	if (g_vm.reg_error)
		return ;
	or = a | b;
	push_register(reg, (char*)&or);
	if (g_vm.option.verbose)
	{
		ft_printf(ADD, COUNT, process->nb, process->id,
				"OR", or, args[2].value);
	}
	if (or != 0)
		process->carry = 0;
	else
		process->carry = 1;
}
