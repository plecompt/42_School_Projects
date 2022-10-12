/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:46:41 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:46:42 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = (size_t)start + len;
	dst = ft_strnew(len);
	if (dst == NULL)
		return (NULL);
	if (s != NULL)
	{
		while (start < j)
		{
			dst[i] = s[start];
			start++;
			i++;
			if (s[start] == '\0')
			{
				dst[i] = s[start];
				return (dst);
			}
		}
		return (dst);
	}
	return (NULL);
}
