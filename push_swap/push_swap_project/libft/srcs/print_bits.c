/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:22:24 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/05 12:07:36 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bits(long long octet)
{
	int n;

	while (octet)
	{
		n = octet & 1llu;
		if (n == 1)
			ft_putstr("1");
		else
			ft_putstr("0");
		octet /= 2;
	}
	ft_putchar('\n');
}
