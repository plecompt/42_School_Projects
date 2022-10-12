/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:38:27 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/29 17:29:03 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_size(char *s1, char *s2, int len_s1, int len_s2)
{
	char	*str;
	char	*str_init;
	int		i;

	i = -1;
	if (!(str = malloc(sizeof(char) * (len_s2 + len_s1 + 1))))
		return (NULL);
	str_init = str;
	if (s1)
	{
		while (len_s1 != 0 && ++i < len_s1)
			*(str++) = *(s1++);
	}
	i = -1;
	if (s2)
	{
		while (len_s2 != 0 && ++i < len_s2)
			*(str++) = *(s2++);
	}
	*(str) = '\0';
	return (str_init);
}
