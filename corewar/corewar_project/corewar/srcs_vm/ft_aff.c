/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:49:59 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 18:51:20 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_aff(t_proc *proc, t_op_arg args[3])
{
	int		value;

	if (!g_vm.option.aff)
		return ;
	value = 0;
	pull_register(get_register(proc->reg, args[0].value), (char*)&value);
	if (!g_vm.reg_error)
		ft_printf(AFF, COUNT, proc->nb, proc->id, value);
}
