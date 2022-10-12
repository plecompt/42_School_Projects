/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:45:43 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:45:44 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			dst[i] = f(i, src[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
