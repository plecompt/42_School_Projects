/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:24:54 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:24:56 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int	value;
	int	i;
	int	pol;
	int i2;

	value = 0;
	i = 0;
	pol = 1;
	i2 = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pol = -1;
		i++;
		i2++;
	}
	while (str[i] && ft_isdigit(str[i]) && (i2 <= 1))
	{
		value = value * 10 + str[i] - '0';
		i++;
	}
	return (value * pol);
}
