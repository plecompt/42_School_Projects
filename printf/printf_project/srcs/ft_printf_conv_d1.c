/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_d1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:55:12 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:08:06 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv_min_d(t_var_printf *var, va_list ap)
{
	int	nb;

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

void	ft_printf_conv_min_d_j(t_var_printf *var, va_list ap)
{
	intmax_t	nb;

	var->signed_conv = 1;
	nb = va_arg(ap, intmax_t);
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

void	ft_printf_conv_min_d_z(t_var_printf *var, va_list ap)
{
	size_t	nb;

	var->signed_conv = 1;
	nb = va_arg(ap, size_t);
	if ((long long int)nb < 0)
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

void	ft_printf_conv_d(t_var_printf *var, va_list ap)
{
	if (var->h)
		ft_printf_conv_min_d_h(var, ap);
	else if (var->hh)
		ft_printf_conv_min_d_hh(var, ap);
	else if (var->l)
		ft_printf_conv_min_d_l(var, ap);
	else if (var->ll)
		ft_printf_conv_min_d_ll(var, ap);
	else if (var->j)
		ft_printf_conv_min_d_j(var, ap);
	else if (var->z)
		ft_printf_conv_min_d_z(var, ap);
	else
		ft_printf_conv_min_d(var, ap);
}
