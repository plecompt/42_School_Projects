/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:49:56 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/09 12:53:34 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_base(char *str, char *base)
{
	char *tmp;
	char *ptr;

	if (!base || !str)
		return (0);
	tmp = NULL;
	ptr = NULL;
	while (*base != '\0')
	{
		if ((tmp = ft_strchr(str, *base)))
			if (tmp < ptr || ptr == NULL)
				ptr = tmp;
		base++;
	}
	return (ptr);
}
