/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:03:31 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 19:04:01 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		write_byte(char *dst, char *src, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

void			write_on_map(char *src, char *pc, size_t size)
{
	char	*map;
	int		overflow;

	if ((map = g_vm.map) > pc)
		pc = ((pc - map) % MEM_SIZE) + map + MEM_SIZE;
	else if (pc > map + MEM_SIZE)
		pc = map + (pc - (map + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + size - (map + MEM_SIZE)) > 0)
	{
		size -= overflow;
		write_byte(map, &src[size], overflow);
	}
	write_byte(pc, src, size);
}

void			read_on_map(char *dst, char *pc, size_t range)
{
	char	*mem;
	int		overflow;

	if ((mem = g_vm.map) > pc)
		pc = ((pc - mem) % MEM_SIZE) + mem + MEM_SIZE;
	else if (pc > mem + MEM_SIZE)
		pc = mem + (pc - (mem + MEM_SIZE)) % MEM_SIZE;
	if ((overflow = pc + range - (mem + MEM_SIZE)) > 0)
	{
		range -= overflow;
		ft_memcpy((void *)&dst[range], (void *)mem, overflow);
	}
	ft_memcpy((void *)dst, (void *)pc, range);
}
