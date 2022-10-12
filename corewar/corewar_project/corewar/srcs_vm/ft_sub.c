/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:58:26 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:34:47 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_sub(t_proc *process, t_op_arg args[3])
{
	int		a;
	int		b;
	int		sub;
	t_reg	*reg;

	a = get_value(process, args, 0, 0);
	b = get_value(process, args, 1, 0);
	reg = get_register(process->reg, args[2].value);
	if (g_vm.reg_error)
		return ;
	sub = a - b;
	push_register(reg, (char*)&sub);
	if (g_vm.option.verbose)
	{
		ft_printf(ADD, COUNT, process->nb, process->id,
				"SUB", sub, args[2].value);
	}
	if (sub != 0)
		process->carry = 0;
	else
		process->carry = 1;
}
