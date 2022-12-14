/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:21:11 by plecompt          #+#    #+#             */
/*   Updated: 2017/01/03 11:55:56 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbuf(char *dest, const char *src, int *len_dest, int n)
{
	char		*str;
	const char	*src_init;
	const char	*ptr;

	src_init = src;
	ptr = src + n;
	str = dest + *len_dest % BUFF_SIZE;
	while (*(src) && src != ptr)
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
