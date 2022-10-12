/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:35:40 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/26 07:36:27 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlen(s));
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] != '\0')
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	j--;
	while (dst[j] == ' ' || (dst[j] >= 9 && dst[j] <= 13))
	{
		dst[j] = '\0';
		j--;
	}
	return (dst);
}
