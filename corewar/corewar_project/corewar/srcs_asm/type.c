/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:22:14 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/14 10:38:18 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_reg(char *str)
{
	if (str[0] == 'r')
		return (1);
	return (0);
}

int		is_direct(char *str)
{
	if (str[0] == '%' && str[1] != ':')
		return (2);
	return (0);
}

int		is_indirect(char *str)
{
	if (str[0] != '%' && str[0] != ':' && str[0] != 'r')
		return (3);
	return (0);
}

int		is_direct_label(char *str)
{
	if (str[0] == '%' && str[1] == ':')
		return (4);
	return (0);
}

int		is_indirect_label(char *str)
{
	if (str[0] == ':')
		return (5);
	return (0);
}
