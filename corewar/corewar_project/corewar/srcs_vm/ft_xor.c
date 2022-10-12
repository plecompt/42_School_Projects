/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:58:52 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/09 12:35:02 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_xor(t_proc *process, t_op_arg args[3])
{
	int		a;
	int		b;
	int		xor;
	t_reg	*reg;

	reg = get_register(process->reg, args[2].value);
	a = get_value(process, args, 0, 0);
	b = get_value(process, args, 1, 0);
	if (g_vm.reg_error)
		return ;
	xor = a ^ b;
	push_register(reg, (char*)&xor);
	if (g_vm.option.verbose)
	{
		ft_printf(ADD, COUNT, process->nb, process->id,
				"XOR", xor, args[2].value);
	}
	if (xor != 0)
		process->carry = 0;
	else
		process->carry = 1;
}
