/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:13:08 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_space_before(t_var_printf *var)
{
	size_t	nb;

	if (!var->minus && !ft_printf_flag_zero(var))
	{
		nb = var->size_min - var->size;
		while ((int)nb > 0)
		{
			if ((var->spec == 'S') || (var->spec ==
						'C') || (((var->spec == 's') || (var->spec ==
									'c')) && (var->l)))
				ft_printf_putstr_ret(var->conv_wspace, var);
			else
				ft_printf_putchar_ret(' ', var);
			nb--;
		}
	}
}

void	ft_printf_signe(t_var_printf *var)
{
	if (var->signed_conv)
	{
		if (var->neg)
			ft_printf_putchar_ret('-', var);
		else if (var->plus)
			ft_printf_putchar_ret('+', var);
		else if (var->space)
			ft_printf_putchar_ret(' ', var);
	}
}

void	ft_printf_sharp_before(t_var_printf *var)
{
	if (var->sharp)
	{
		if (((var->spec == 'o') || (var->spec == 'O')) &&
				(!var->pres_zero) && ((var->conv_ullong) || ((!var->conv_ullong)
						&& (var->have_pres) && (!var->pres))))
			ft_printf_putchar_ret('0', var);
		if (((var->spec == 'x') && (var->conv_ullong != 0)) ||
				(var->spec == 'p'))
			ft_printf_putstr_ret("0x", var);
		if ((var->spec == 'X') && (var->conv_ullong != 0))
			ft_printf_putstr_ret("0X", var);
	}
}

void	ft_printf_zero_before(t_var_printf *var)
{
	size_t	nb;

	if (!var->minus && ft_printf_flag_zero(var))
	{
		nb = var->size_min - var->size;
		while ((int)nb > 0)
		{
			if ((var->spec == 'S') || (var->spec ==
						'C') || (((var->spec == 's') || (var->spec ==
									'c')) && (var->l)))
				ft_printf_putstr_ret(var->conv_wzero, var);
			else
				ft_printf_putchar_ret('0', var);
			nb--;
		}
	}
	while ((int)var->pres_zero > 0)
	{
		ft_printf_putchar_ret('0', var);
		var->pres_zero = var->pres_zero - 1;
	}
}

void	ft_printf_space_after(t_var_printf *var)
{
	size_t	nb;

	if (var->minus)
	{
		nb = var->size_min - var->size;
		while ((int)nb > 0)
		{
			if ((var->spec == 'S') || (var->spec ==
						'C') || (((var->spec == 's') || (var->spec ==
									'c')) && (var->l)))
				ft_printf_putstr_ret(var->conv_wspace, var);
			else
				ft_printf_putchar_ret(' ', var);
			nb--;
		}
	}
}
