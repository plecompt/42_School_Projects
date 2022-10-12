/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 17:32:59 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_hljz_raz(t_var_printf *var)
{
	var->h = 0;
	var->hh = 0;
	var->l = 0;
	var->ll = 0;
	var->j = 0;
	var->z = 0;
}

void	ft_printf_conv_raz(t_var_printf *var)
{
	var->conv_llong = 0;
	var->conv_ullong = 0;
	var->conv_char = 0;
	var->conv_temp = NULL;
	var->conv_str = NULL;
}

void	ft_printf_var_raz(t_var_printf *var)
{
	var->i = 0;
	var->t = 0;
	var->sharp = 0;
	var->zero = 0;
	var->minus = 0;
	var->plus = 0;
	var->space = 0;
	var->size_min = 0;
	var->size = 0;
	var->size_temp = 0;
	var->pres = 0;
	var->have_pres = 0;
	var->spec = 0;
	var->neg = 0;
	var->conv = 0;
	var->signed_conv = 0;
	var->pres_zero = 0;
	var->base = 0;
	var->ubase = 0;
	var->wchar = 0;
	var->wstr = NULL;
	var->str_base = NULL;
	ft_printf_hljz_raz(var);
	ft_printf_conv_raz(var);
}

void	ft_printf_var_init(t_var_printf *var)
{
	var->first = 1;
	var->ret = 0;
	var->str = NULL;
	var->temp = NULL;
	var->temp2 = NULL;
	ft_printf_conv_wspace(var);
	ft_printf_conv_wzero(var);
	ft_printf_var_raz(var);
}
