/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:56:29 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 11:52:28 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_print(t_var_printf *var)
{
	ft_printf_space_before(var);
	ft_printf_signe(var);
	ft_printf_sharp_before(var);
	ft_printf_zero_before(var);
	if (var->conv_str)
	{
		ft_printf_putstr_conv_char(var);
		if ((var->spec == 'S') || (var->spec == 's' && var->l) ||
				(var->spec == 'C') || (var->spec == 'c' && var->l))
			free(var->conv_str);
	}
	else if (var->spec == 'd' || var->spec == 'D' || var->spec == 'x' ||
			var->spec == 'X' || var->spec == 'u' || var->spec == 'U' ||
			var->spec == 'o' || var->spec == 'O' || var->spec == 'i' ||
			var->spec == 'p')
		ft_printf_putnbr_ret(var);
	else
		ft_printf_putchar_ret(var->conv_char, var);
	ft_printf_space_after(var);
}
