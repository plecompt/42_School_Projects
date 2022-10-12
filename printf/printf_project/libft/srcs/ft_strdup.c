/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:56:32 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:56:32 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = NULL;
	if (s1 != NULL)
	{
		if ((dest = malloc(sizeof(char) * (ft_strlen(s1) + 1))) == 0)
			return (NULL);
		else
		{
			while (s1[i])
			{
				dest[i] = s1[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (dest);
}
