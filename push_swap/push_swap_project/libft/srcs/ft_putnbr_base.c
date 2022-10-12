/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 13:28:19 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/10 12:32:28 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		error_base(char *base, int size)
{
	int		i;
	int		j;
	char	tmp[size];

	i = 0;
	if (base == 0)
		return (0);
	while (base[i])
	{
		tmp[i] = base[i];
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		i++;
		while (tmp[j])
		{
			if (tmp[j] == base[i])
				return (0);
			j++;
		}
	}
	return (1);
}

static void		ft_recurs(int nbr, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < (int)ft_strlen(base))
	{
		ft_putchar(base[nbr]);
	}
	else
	{
		ft_recurs(nbr / ft_strlen(base), base);
		ft_recurs(nbr % ft_strlen(base), base);
	}
}

void			ft_putnbr_base(int nbr, char *base)
{
	if (error_base(base, ft_strlen(base)) == 0)
		return ;
	ft_recurs(nbr, base);
}
