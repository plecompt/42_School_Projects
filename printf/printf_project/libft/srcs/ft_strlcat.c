/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:59:32 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:59:33 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size <= len1)
		return (size + len2);
	if (len2 < size - len1)
	{
		ft_memcpy(dst + len1, src, len2);
		dst += len1 + len2;
	}
	else
	{
		ft_memcpy(dst + len1, src, size - len1 - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (len1 + len2);
}
