/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:12:20 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/05 17:53:57 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char				get_byte_index(char *address)
{
	int			overflow;

	if ((overflow = address - (g_vm.map + MEM_SIZE)) >= 0)
		return (g_vm.map[overflow]);
	return (*address);
}

void				kill_process(int count)
{
	t_proc		*old_process;
	int			i;
	int			j;

	old_process = g_vm.process;
	g_vm.process = NULL;
	if (count)
	{
		if (!(g_vm.process = (t_proc*)ft_memalloc(sizeof(t_proc) * count)))
			error("Memory", "allocation error on kill_process");
		i = -1;
		j = 0;
		while (++i < g_vm.process_count)
		{
			if (old_process[i].live)
			{
				old_process[i].live = 0;
				if (j < count)
					ft_memcpy(&g_vm.process[j++], &old_process[i],
							sizeof(t_proc));
			}
		}
	}
	free(old_process);
	g_vm.process_count = count;
}

t_proc				*create_process(char *pc, t_proc *parent, int nb)
{
	static unsigned int	uid = 0;
	t_proc				*new_proc;
	t_proc				buf;
	int					count;

	ft_bzero(&buf, sizeof(t_proc));
	if (parent)
		ft_memcpy(&buf, parent, sizeof(t_proc));
	g_vm.process_count++;
	count = g_vm.process_count;
	g_vm.process = realloc(g_vm.process, sizeof(t_proc) * count);
	if (!g_vm.process)
		error("Memory", "allocation error on create_process");
	new_proc = &g_vm.process[count - 1];
	ft_bzero(new_proc, sizeof(t_proc));
	new_proc->pc = pc;
	if (parent)
		ft_memcpy(new_proc, &buf, sizeof(t_proc));
	rev_cpy((char*)&new_proc->reg[0], (char*)&nb, REG_SIZE);
	new_proc->nb = -nb;
	new_proc->id = ++uid;
	new_proc->wait = -1;
	new_proc->op = NULL;
	return (new_proc);
}

char				*go_next_op(t_proc *process, int offset)
{
	char	*pc;
	char	*mem;

	process->op = NULL;
	process->wait = -1;
	pc = process->pc + offset;
	if ((mem = g_vm.map) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	process->pc = pc;
	return (pc);
}

void				lunch_process(void)
{
	t_proc			*process;
	int				opcode;
	int				offset;
	int				i;

	i = g_vm.process_count;
	while (--i >= 0)
	{
		process = &g_vm.process[i];
		if (process->wait < 0)
		{
			opcode = (int)get_byte_index(process->pc) - 1;
			if (opcode >= 0 && opcode < OP_COUNT)
			{
				process->op = &g_op_tab[opcode];
				process->wait = g_op_tab[opcode].nbr_cycle;
			}
		}
		if (--process->wait <= 0)
		{
			offset = lunch_do_op(process);
			go_next_op(&g_vm.process[i], offset);
		}
	}
}
