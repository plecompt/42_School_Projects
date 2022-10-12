/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:58:36 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:12:23 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_flag_zero(t_var_printf *var)
{
	if (var->zero)
	{
		if ((var->have_pres) && (var->spec == 'd'
					|| var->spec == 'i' || var->spec == 'o'
					|| var->spec == 'O' || var->spec == 'U'
					|| var->spec == 'x' || var->spec == 'X'))
			return (0);
		else
			return (1);
	}
	return (0);
}
