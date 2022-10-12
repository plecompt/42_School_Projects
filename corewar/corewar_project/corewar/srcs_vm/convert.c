/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:02:23 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/05 17:09:36 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		rev_cpy(char *dst, char *src, size_t type_size)
{
	int		i;

	i = type_size - 1;
	if (!dst && !src)
		return ;
	while (i >= 0)
	{
		dst[i] = src[type_size - (i + 1)];
		i--;
	}
}

t_reg		*get_register(t_reg *registers, int value)
{
	if (value < 1 || value > REG_NUMBER)
	{
		g_vm.reg_error = 1;
		return (NULL);
	}
	return (&registers[value - 1]);
}

void		push_register(t_reg reg[REG_SIZE], char *value)
{
	if (reg)
		rev_cpy((char*)reg, value, REG_SIZE);
}

void		pull_register(t_reg reg[REG_SIZE], char *value)
{
	if (reg)
		rev_cpy(value, (char*)reg, REG_SIZE);
}

void		copy_register(t_reg r1[REG_SIZE], t_reg r2[REG_SIZE])
{
	if (r1 && r2)
		ft_memcpy((void *)r1, (void *)r2, REG_SIZE);
}
