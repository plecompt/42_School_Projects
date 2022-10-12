/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:55:02 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:05:52 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv_min_c(t_var_printf *var, va_list ap)
{
	var->conv_char = (char)va_arg(ap, int);
	var->size = 1;
}

void	ft_printf_conv_min_c_l(t_var_printf *var, va_list ap)
{
	var->wchar = va_arg(ap, wchar_t);
	if (var->wchar)
	{
		var->conv_temp = ft_memalloc(5);
		var->size_temp = 1;
		ft_printf_conv_unicode(var);
		var->conv_str = var->conv_temp;
		var->size = ft_strlen(var->conv_str);
	}
	else
		var->conv_char = 0;
}

void	ft_printf_conv_wspace(t_var_printf *var)
{
	var->wchar = L' ';
	var->conv_temp = ft_memalloc(5);
	var->size_temp = 1;
	ft_printf_conv_unicode(var);
	var->conv_wspace = var->conv_temp;
}

void	ft_printf_conv_wzero(t_var_printf *var)
{
	var->wchar = L'0';
	var->conv_temp = ft_memalloc(5);
	var->size_temp = 1;
	ft_printf_conv_unicode(var);
	var->conv_wzero = var->conv_temp;
}

void	ft_printf_conv_c(t_var_printf *var, va_list ap)
{
	if (var->l)
		ft_printf_conv_min_c_l(var, ap);
	else
		ft_printf_conv_min_c(var, ap);
}
