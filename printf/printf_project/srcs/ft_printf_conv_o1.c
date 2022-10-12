/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_o1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:55:31 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:10:15 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv_min_o(t_var_printf *var, va_list ap)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	var->conv_ullong = (unsigned long long int)nb;
	var->ubase = 8;
	var->str_base = "01234567";
	var->size = ft_unbrlen_base(var->conv_ullong, var->ubase);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->sharp == 1) && (!var->pres_zero))
		var->size = var->size + 1;
}

void	ft_printf_conv_min_o_j(t_var_printf *var, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	var->conv_ullong = (unsigned long long int)nb;
	var->ubase = 8;
	var->str_base = "01234567";
	var->size = ft_unbrlen_base(var->conv_ullong, var->ubase);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->sharp == 1) && (!var->pres_zero))
		var->size = var->size + 1;
}

void	ft_printf_conv_min_o_z(t_var_printf *var, va_list ap)
{
	size_t	nb;

	nb = va_arg(ap, size_t);
	var->conv_ullong = (unsigned long long int)nb;
	var->ubase = 8;
	var->str_base = "01234567";
	var->size = ft_unbrlen_base(var->conv_ullong, var->ubase);
	if ((var->have_pres) && (var->size < var->pres))
	{
		var->pres_zero = var->pres - var->size;
		var->size = var->pres;
	}
	if ((var->sharp == 1) && (!var->pres_zero))
		var->size = var->size + 1;
}

void	ft_printf_conv_o(t_var_printf *var, va_list ap)
{
	if (var->h)
		ft_printf_conv_min_o_h(var, ap);
	else if (var->hh)
		ft_printf_conv_min_o_hh(var, ap);
	else if (var->l)
		ft_printf_conv_min_o_l(var, ap);
	else if (var->ll)
		ft_printf_conv_min_o_ll(var, ap);
	else if (var->j)
		ft_printf_conv_min_o_j(var, ap);
	else if (var->z)
		ft_printf_conv_min_o_z(var, ap);
	else
		ft_printf_conv_min_o(var, ap);
}
