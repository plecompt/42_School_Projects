/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:59:20 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/06 15:43:36 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	conv;
	int		i;

	i = ft_strlen(s) + 1;
	conv = (char)c;
	while (i > 0 && s[i - 1] != conv)
		i--;
	if (i > 0)
		return ((char *)s + i - 1);
	return (NULL);
}
