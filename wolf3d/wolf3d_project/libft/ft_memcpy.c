/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:09:22 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/11 15:18:21 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dstx;
	char		*srcx;

	dstx = (char *)dst;
	srcx = (char *)src;
	i = 0;
	while (i < n)
	{
		dstx[i] = srcx[i];
		i++;
	}
	return (dstx);
}
