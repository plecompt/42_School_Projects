/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:18:53 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/15 17:54:53 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t j;

	j = 0;
	while (*dest)
		dest++;
	while (src[j] && j != n)
		*(dest++) = src[j++];
	*dest = '\0';
	return (dest);
}
