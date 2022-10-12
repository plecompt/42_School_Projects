/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:49:15 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:32:21 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_add(t_proc *process, t_op_arg args[3])
{
	int		a;
	int		b;
	int		add;

	a = get_value(process, args, 0, 0);
	b = get_value(process, args, 1, 0);
	if (g_vm.reg_error)
		return ;
	add = a + b;
	push_register(get_register(process->reg, args[2].value), (char*)&add);
	if (g_vm.reg_error)
		return ;
	if (g_vm.option.verbose)
	{
		ft_printf(ADD, COUNT, process->nb, process->id,
				"add", add, args[2].value);
	}
	if (add != 0)
		process->carry = 0;
	else
		process->carry = 1;
}
