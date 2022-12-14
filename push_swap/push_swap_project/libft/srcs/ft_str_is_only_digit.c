/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_only_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:34:54 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/19 15:17:21 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_str_is_only_digit(char *str)
{
	int i;

	if (!str)
		return (1);
	if ((!ft_isdigit(str[0]) && (str[0] != '-' && str[0] != '+'))
	|| (!ft_isdigit(str[1]) && (str[0] == '-' && str[0] == '+')))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}
