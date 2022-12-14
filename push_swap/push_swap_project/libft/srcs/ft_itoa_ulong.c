/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:54:32 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/16 15:22:27 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_ulong(unsigned long long n)
{
	char				*s_nb;
	int					len;
	unsigned long long	n_cpy;

	n_cpy = n;
	len = 2;
	while (n_cpy /= 10)
		len++;
	if ((s_nb = malloc(sizeof(char) * (len))) == NULL)
		return (NULL);
	s_nb[--len] = '\0';
	while (len--)
	{
		s_nb[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s_nb);
}
