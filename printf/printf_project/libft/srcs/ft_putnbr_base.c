/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:43:58 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:44:04 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_base(long long int nb, char *str_base)
{
	int	base;

	base = (int)ft_strlen(str_base);
	if (nb < 0)
	{
		if (nb <= -base)
		{
			ft_putnbr_base(nb / -base, str_base);
			ft_putnbr_base(nb % -base, str_base);
		}
		else
			ft_putchar(str_base[-nb]);
	}
	else
	{
		if (nb >= base)
		{
			ft_putnbr_base(nb / base, str_base);
			ft_putnbr_base(nb % base, str_base);
		}
		else
			ft_putchar(str_base[nb]);
	}
}
