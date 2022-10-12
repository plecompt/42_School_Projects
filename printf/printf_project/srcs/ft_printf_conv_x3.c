/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_x3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:59:06 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:11:38 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv_maj_x(t_var_printf *var, va_list ap)
{
	unsigned int	nb;

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

void	ft_printf_conv_maj_x_j(t_var_printf *var, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
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

void	ft_printf_conv_maj_x_z(t_var_printf *var, va_list ap)
{
	size_t	nb;

	nb = va_arg(ap, size_t);
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

void	ft_printf_conv_x_2(t_var_printf *var, va_list ap)
{
	if (var->h)
		ft_printf_conv_maj_x_h(var, ap);
	else if (var->hh)
		ft_printf_conv_maj_x_hh(var, ap);
	else if (var->l)
		ft_printf_conv_maj_x_l(var, ap);
	else if (var->ll)
		ft_printf_conv_maj_x_ll(var, ap);
	else if (var->j)
		ft_printf_conv_maj_x_j(var, ap);
	else if (var->z)
		ft_printf_conv_maj_x_z(var, ap);
	else
		ft_printf_conv_maj_x(var, ap);
}
