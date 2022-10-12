/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:30:00 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:30:01 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	*ft_itoa_intmin(int n)
{
	char	*dest;

	if (n == -2147483648)
	{
		dest = ft_strnew(11);
		if (dest == NULL)
			return (NULL);
		dest[0] = '-';
		dest[1] = '2';
		dest[2] = '1';
		dest[3] = '4';
		dest[4] = '7';
		dest[5] = '4';
		dest[6] = '8';
		dest[7] = '3';
		dest[8] = '6';
		dest[9] = '4';
		dest[10] = '8';
		dest[11] = '\0';
		return (dest);
	}
	return (NULL);
}

char			*ft_itoa(int n)
{
	int		ncpy;
	size_t	i;
	size_t	len;
	char	*str;

	i = 1;
	ncpy = n;
	if ((str = ft_itoa_intmin(n)) != NULL)
		return (str);
	while (ncpy /= 10)
		i++;
	len = i;
	if (!(str = ft_strnew(n < 0 ? len + 1 : len)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		len++;
		str[0] = '-';
	}
	str[--len] = n % 10 + '0';
	while (n /= 10)
		str[--len] = n % 10 + '0';
	return (str);
}
