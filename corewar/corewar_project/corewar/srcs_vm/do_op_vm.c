/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:43:13 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 18:47:32 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			get_value(t_proc *process, t_op_arg *arg, int i, int long_op)
{
	char		buf[DIR_SIZE];
	t_arg_type	type;
	int			value;
	int			ret;

	ret = 0;
	type = arg[i].type;
	value = arg[i].value;
	if (!(type & process->op->args[i]))
		return (0);
	else if (type & T_DIR)
		ret = (process->op->idx) ? (short)value : value;
	else if (type & T_REG)
		pull_register(get_register(process->reg, value), (char*)&ret);
	else if (type & T_IND)
	{
		value = (long_op) ? (short)value : ((short)value) % IDX_MOD;
		ft_bzero(&buf, DIR_SIZE);
		read_on_map((char *)&buf, process->pc + value, DIR_SIZE);
		rev_cpy((char*)&ret, (char *)&buf, DIR_SIZE);
	}
	return (ret);
}

static int	check_ocp(t_proc *process, t_op_arg args[3])
{
	int		i;

	i = 0;
	while (i < process->op->nbr_args)
	{
		if (!(args[i].type & process->op->args[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	do_op_vm(void (*ft_op_vm)(t_proc *, t_op_arg[3]), t_proc *proc)
{
	t_op_arg	args[3];
	int			offset;
	int			nb_player;

	proc->wait = -1;
	g_vm.reg_error = 0;
	nb_player = 0;
	offset = get_argument_op(proc, proc->op->op_code - 1, args);
	pull_register(&proc->reg[0], (char*)&nb_player);
	if (ft_op_vm == &ft_zjmp)
	{
		ft_op_vm(proc, args);
		return (0);
	}
	if (!proc->op->codage_octal || check_ocp(proc, args))
		ft_op_vm(proc, args);
	return (offset);
}

int			lunch_do_op(t_proc *process)
{
	static void		(*ft_op_vm[OP_COUNT])(t_proc *, t_op_arg[3]) = {
		&ft_live,
		&ft_ld,
		&ft_st,
		&ft_add,
		&ft_sub,
		&ft_and,
		&ft_or,
		&ft_xor,
		&ft_zjmp,
		&ft_ldi,
		&ft_sti,
		&ft_fork,
		&ft_lld,
		&ft_lldi,
		&ft_lfork,
		&ft_aff
	};

	if (process->op == NULL)
		return (1);
	return (do_op_vm(ft_op_vm[process->op->op_code - 1], process));
}
