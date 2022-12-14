/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:17:17 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/14 12:07:45 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	i_in_match;
	char	*ptr;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		i_in_match = i;
		ptr = (char*)&haystack[i];
		if (needle[j] == haystack[i])
			while (needle[j] == haystack[i] && haystack[i])
			{
				if (needle[j + 1] == '\0')
					return (ptr);
				j++;
				i++;
			}
		i = i_in_match;
		i++;
	}
	return (NULL);
}
