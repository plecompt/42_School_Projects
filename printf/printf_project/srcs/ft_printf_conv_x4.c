/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_x4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:59:16 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:11:43 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv_maj_x_h(t_var_printf *var, va_list ap)
{
	unsigned short int	nb;

	nb = va_arg(ap, unsigned int);
	var->conv_ullong = (unsigned long long int)nb;
	var->ubase = 16;
	var->str_base = "0123456789ABCDEF";
	var->size = ft_unbrlen_base(var->conv_ullong, var->ubase);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->sharp == 1) && (!var->pres_zero))
		var->size = var->size + 2;
}

void	ft_printf_conv_maj_x_hh(t_var_printf *var, va_list ap)
{
	unsigned char	nb;

	nb = va_arg(ap, unsigned int);
	var->conv_ullong = (unsigned long long int)nb;
	var->ubase = 16;
	var->str_base = "0123456789ABCDEF";
	var->size = ft_unbrlen_base(var->conv_ullong, var->ubase);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->sharp == 1) && (!var->pres_zero))
		var->size = var->size + 2;
}

void	ft_printf_conv_maj_x_l(t_var_printf *var, va_list ap)
{
	unsigned long int	nb;

	nb = va_arg(ap, unsigned long int);
	var->conv_ullong = (unsigned long long int)nb;
	var->ubase = 16;
	var->str_base = "0123456789ABCDEF";
	var->size = ft_unbrlen_base(var->conv_ullong, var->ubase);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->sharp == 1) && (!var->pres_zero))
		var->size = var->size + 2;
}

void	ft_printf_conv_maj_x_ll(t_var_printf *var, va_list ap)
{
	unsigned long long int	nb;

	nb = va_arg(ap, unsigned long long int);
	var->conv_ullong = (unsigned long long int)nb;
	var->ubase = 16;
	var->str_base = "0123456789ABCDEF";
	var->size = ft_unbrlen_base(var->conv_ullong, var->ubase);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->sharp == 1) && (!var->pres_zero))
		var->size = var->size + 2;
}
