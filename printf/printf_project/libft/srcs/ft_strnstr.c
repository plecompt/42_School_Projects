/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:46:18 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:46:19 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen(s2);
	if (!s2)
		return ((char *)s1);
	if (!n || n < len)
		return (NULL);
	j = (n > len) ? len : n;
	while (s1[i] != '\0' && i < n)
	{
		if (n - i < j)
			return (NULL);
		if (ft_strncmp(s1 + i, s2, j) == 0)
			return (char *)(&(s1[i]));
		i++;
	}
	return (NULL);
}
