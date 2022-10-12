/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:40:14 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:40:15 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*t;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst || !src)
		return (NULL);
	t = (unsigned char *)malloc(sizeof(*t) * len);
	ft_memcpy(t, s, len);
	ft_memcpy(d, t, len);
	free(t);
	return (dst);
}
