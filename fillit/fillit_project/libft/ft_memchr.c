/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:05:10 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/12 16:00:58 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*stmp;
	size_t				i;

	if (!s || !n)
		return (NULL);
	stmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (stmp[i] == (unsigned char)c)
			return ((void *)(stmp + i));
		i++;
	}
	return (NULL);
}
