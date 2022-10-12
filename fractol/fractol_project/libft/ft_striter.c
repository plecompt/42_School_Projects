/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:15:40 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/10 17:24:21 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	size_t i;
	size_t l;

	l = ft_strlen(s);
	i = 0;
	if (s != NULL && f != NULL)
	{
		while (i < l)
		{
			(*f)(s);
			s++;
			i++;
		}
	}
}