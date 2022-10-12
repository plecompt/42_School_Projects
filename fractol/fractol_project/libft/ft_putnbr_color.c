/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 08:36:46 by plecompt          #+#    #+#             */
/*   Updated: 2015/02/11 12:12:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_color(int n, int color, int out)
{
	if (n == -2147483648)
	{
		ft_putstr_color("-2147483648", color, out);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_color('-', color, out);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_color(n / 10, color, out);
		ft_putnbr_color(n % 10, color, out);
	}
	else
		ft_putchar_color(n + '0', color, out);
}
