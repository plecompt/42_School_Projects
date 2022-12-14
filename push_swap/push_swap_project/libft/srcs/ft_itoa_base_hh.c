/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:10:05 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/15 17:03:32 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_n_is_negativ(char *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa_base_hh(char n, char *base)
{
	char			*s_nb;
	int				len;
	int				n_cpy;
	int				neg;

	neg = 0;
	n_cpy = n;
	len = 2;
	ft_n_is_negativ(&n, &neg);
	len += neg;
	while (n_cpy /= ft_strlen(base))
		len++;
	if ((s_nb = malloc(sizeof(char) * (len))) == NULL)
		return (NULL);
	s_nb[--len] = '\0';
	while (len--)
	{
		s_nb[len] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	if (neg)
		s_nb[0] = '-';
	return (s_nb);
}
