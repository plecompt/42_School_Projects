/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:13:27 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/06 18:20:55 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	conv;
	char			*rend;
	size_t			i;

	conv = (unsigned char)c;
	rend = (char *)b;
	i = 0;
	while (i < len)
	{
		rend[i] = conv;
		i++;
	}
	return (rend);
}
