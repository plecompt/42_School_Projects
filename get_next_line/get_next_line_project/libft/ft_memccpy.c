/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:32:21 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/11 15:13:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dpter;
	unsigned char	*spter;
	unsigned char	convert;
	size_t			i;

	dpter = (unsigned char *)dst;
	spter = (unsigned char *)src;
	convert = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*dpter++ = *spter++) == convert)
			return (dpter);
		i++;
	}
	return (NULL);
}
