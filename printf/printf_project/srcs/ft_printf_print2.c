/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 11:49:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_putchar_ret(char c, t_var_printf *var)
{
	if (var->spec != 'S')
		var->ret = var->ret + 1;
	ft_putchar(c);
}

void	ft_printf_putstr_conv_char(t_var_printf *var)
{
	var->ret = var->ret + var->size;
	write(1, var->conv_str, var->size);
}

void	ft_printf_putstr_ret(char *str, t_var_printf *var)
{
	var->ret = var->ret + ft_strlen(str);
	ft_putstr(str);
}

void	ft_printf_putnbr_ret(t_var_printf *var)
{
	if (var->signed_conv)
	{
		if (!((var->spec == 'd' || var->spec == 'i' ||
						var->spec == 'D') && (var->conv_llong == 0) &&
					(var->have_pres) && (!var->pres)))
		{
			var->ret = var->ret + ft_nbrlen_base(var->conv_llong,
					var->base);
			ft_putnbr_base(var->conv_llong, var->str_base);
		}
	}
	else
	{
		if (!((var->spec == 'o' || var->spec == 'O' || var->spec ==
						'u' || var->spec == 'U' || var->spec == 'x' ||
						var->spec == 'X' || var->spec == 'p') &&
					(var->conv_ullong == 0) &&
					(var->have_pres) && (!var->pres)))
		{
			var->ret = var->ret + ft_unbrlen_base(var->conv_ullong,
					var->ubase);
			ft_putunbr_base(var->conv_ullong, var->str_base);
		}
	}
}
