/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_d2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:55:23 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:10:06 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv_min_d_h(t_var_printf *var, va_list ap)
{
	short int	nb;

	var->signed_conv = 1;
	nb = va_arg(ap, int);
	if (nb < 0)
		var->neg = 1;
	var->conv_llong = (long long int)nb;
	var->base = 10;
	var->str_base = "0123456789";
	var->size = ft_nbrlen_base(var->conv_llong, var->base);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->neg == 1) || (var->plus) || (var->space))
		var->size = var->size + 1;
}

void	ft_printf_conv_min_d_hh(t_var_printf *var, va_list ap)
{
	char	nb;

	var->signed_conv = 1;
	nb = va_arg(ap, int);
	if (nb < 0)
		var->neg = 1;
	var->conv_llong = (long long int)nb;
	var->base = 10;
	var->str_base = "0123456789";
	var->size = ft_nbrlen_base(var->conv_llong, var->base);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->neg == 1) || (var->plus) || (var->space))
		var->size = var->size + 1;
}

void	ft_printf_conv_min_d_l(t_var_printf *var, va_list ap)
{
	long int	nb;

	var->signed_conv = 1;
	nb = va_arg(ap, long int);
	if (nb < 0)
		var->neg = 1;
	var->conv_llong = (long long int)nb;
	var->base = 10;
	var->str_base = "0123456789";
	var->size = ft_nbrlen_base(var->conv_llong, var->base);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->neg == 1) || (var->plus) || (var->space))
		var->size = var->size + 1;
}

void	ft_printf_conv_min_d_ll(t_var_printf *var, va_list ap)
{
	long long int	nb;

	var->signed_conv = 1;
	nb = va_arg(ap, long long int);
	if (nb < 0)
		var->neg = 1;
	var->conv_llong = (long long int)nb;
	var->base = 10;
	var->str_base = "0123456789";
	var->size = ft_nbrlen_base(var->conv_llong, var->base);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->neg == 1) || (var->plus) || (var->space))
		var->size = var->size + 1;
}
