/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:42:09 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/18 11:42:17 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa_base(int value, int base)
{
	char *base_convert = "0123456789ABCDEF";
	int nb_convert[64];
	char *ret;
	int i = 0;
	int nb value < 0 ? -value : value;
	int n = 0;
	if (value == 0)
		return ("0");
	if (value == -2147483648)
		return ("-2147483648");
	while (nb != 0)
	{
		nb_convert[i] = nb % base;
		i++;
		nb = nb  / base;
	}
	if (!(ret = (char *)malloc(sizeof(char) * i)))
		return NULL;
	if (value < 0 && base == 10)
	{
		ret[0] = '-';
		n = 1;
	}
	while (i > 0)
	{
		ret[n] = base_convert[nb_convert[i - 1]];
		i--;
		n++;
	}
	ret[n] = '\0';
	return ret;
}
