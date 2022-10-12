/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:54:30 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/06 11:52:37 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	conv;
	int		i;

	conv = (char)c;
	i = 0;
	while (s[i] && s[i] != conv)
		i++;
	if (s[i] == conv)
		return ((char *)s + i);
	return (NULL);
}
