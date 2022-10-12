/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:59:42 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 19:00:53 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		get_type_of_arg(t_op_arg *arg, char code_arg, int opcode)
{
	if (code_arg == REG_CODE)
	{
		arg->type = T_REG;
		arg->size = 1;
	}
	else if (code_arg == IND_CODE)
	{
		arg->type = T_IND;
		arg->size = IND_SIZE;
	}
	else if (code_arg == DIR_CODE)
	{
		arg->type = T_DIR;
		arg->size = (g_op_tab[opcode].idx) ? IND_SIZE : DIR_SIZE;
	}
	else
	{
		arg->type = 0;
		arg->size = 0;
	}
}

static size_t	check_args(t_op_arg args[3], char c_arg, int opcode, int count)
{
	if (!g_op_tab[opcode].codage_octal)
	{
		if (g_op_tab[opcode].idx)
		{
			args[0].size = IND_SIZE;
			args[0].type = T_IND;
		}
		else
		{
			args[0].size = DIR_SIZE;
			args[0].type = T_DIR;
		}
		return (1);
	}
	args[1].type = 0;
	args[1].size = 0;
	args[2].type = 0;
	args[2].size = 0;
	get_type_of_arg(&args[0], (c_arg & 0b11000000) >> 6, opcode);
	if (count > 1)
		get_type_of_arg(&args[1], (c_arg & 0b00110000) >> 4, opcode);
	if (count > 2)
		get_type_of_arg(&args[2], (c_arg & 0b00001100) >> 2, opcode);
	return (2);
}

static void		pull_arguments(char *pc, t_op_arg args[3], int count_args)
{
	char	*value_ptr;
	int		offset;
	int		size;
	int		i;
	int		j;

	i = -1;
	offset = 0;
	while (++i < count_args)
	{
		j = -1;
		size = args[i].size;
		value_ptr = (char *)&args[i].value;
		while (++j < size)
			value_ptr[size - (j + 1)] = get_byte_index(pc + offset + j);
		offset += args[i].size;
	}
}

size_t			get_argument_op(t_proc *process, int opcode, t_op_arg args[3])
{
	size_t	offset;
	int		count_args;
	int		args_sizes;

	ft_bzero(args, sizeof(t_op_arg) * 3);
	count_args = g_op_tab[opcode].nbr_args;
	offset = check_args(args, get_byte_index(process->pc + 1),
			opcode, count_args);
	args_sizes = args[0].size + args[1].size + args[2].size;
	if (args_sizes > 0)
		pull_arguments((char *)&process->pc[offset], args, count_args);
	return (offset + args_sizes);
}
