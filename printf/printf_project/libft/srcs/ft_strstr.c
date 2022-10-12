/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:46:36 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:46:36 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	diff;

	if (!s2 || ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		diff = 0;
		j = 0;
		while ((s2[j] != '\0') && !diff)
		{
			if (s2[j] != s1[i + j])
				diff = 1;
			if (s1[i + j] == '\0')
				return (NULL);
			j++;
		}
		if (!diff)
			return ((char *)&(s1[i]));
		i++;
	}
	return (NULL);
}
