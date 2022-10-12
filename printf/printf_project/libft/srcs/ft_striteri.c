/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:56:50 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:56:51 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	if (s != NULL && f != NULL)
	{
		l = ft_strlen(s);
		while (i < l)
		{
			(*f)(i, s + i);
			i++;
		}
	}
}
