/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:54:16 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/18 17:40:50 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(s_dup = malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (s_dup == NULL)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		if (s[i])
			s_dup[i] = s[i];
		else
			s_dup[i] = '\0';
		i++;
	}
	return (s_dup);
}
