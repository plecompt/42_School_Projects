/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 04:36:45 by plecompt          #+#    #+#             */
/*   Updated: 2015/01/15 07:45:16 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getnbr(char *str)
{
	int		res;

	res = 0;
	if (str != NULL && str[0] == '-')
		return (-ft_getnbr(&str[1]));
	if (str != NULL && str[0] == '+')
		str[0] = '0';
	while ((*str >= '0') && (*str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res);
}
