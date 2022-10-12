/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:59:49 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:59:50 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*src;
	char	*dst;

	i = 0;
	if ((s != NULL) && (f != NULL))
	{
		src = (char*)s;
		dst = ft_strnew(ft_strlen(s));
		while (src[i])
		{
			dst[i] = f(src[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
