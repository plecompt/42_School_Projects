/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:20:53 by plecompt          #+#    #+#             */
/*   Updated: 2017/01/03 11:55:05 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbuf(char *dest, const char *src, int *len_dest)
{
	char		*str;
	const char	*src_init;

	src_init = src;
	str = dest + *len_dest % BUFF_SIZE;
	while (*(src))
	{
		*(str++) = *(src++);
		if (*len_dest % BUFF_SIZE >= BUFF_SIZE - 1)
		{
			write(1, dest, BUFF_SIZE);
			ft_bzero(dest, BUFF_SIZE);
			str = dest;
		}
		(*len_dest)++;
	}
	*str = '\0';
}
