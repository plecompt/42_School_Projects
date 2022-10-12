/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:39:15 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/10 15:23:57 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if ((s1 && s1[i]) && (s2 && s2[i]))
	{
		while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
			i++;
	}
	else
		return (-1);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
