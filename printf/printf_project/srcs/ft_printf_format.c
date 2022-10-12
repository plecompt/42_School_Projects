/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:15:10 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 11:51:04 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_format_analyze(t_var_printf *var, va_list ap)
{
	ft_printf_find_flag(var);
	var->spec = var->str[0];
	if (var->spec)
	{
		ft_printf_spec_id(var, ap);
		ft_printf_print(var);
		var->str = var->str + 1;
		if ((var->temp = ft_strchr(var->str, '%')) == NULL)
		{
			ft_printf_putstr_ret(var->str, var);
			while (var->str[0])
				var->str = var->str + 1;
		}
		else
		{
			var->temp[0] = '\0';
			ft_printf_putstr_ret(var->str, var);
			var->temp[0] = '%';
			var->str = var->temp + 1;
		}
	}
	ft_printf_var_raz(var);
}

void	ft_printf_format(const char *format, t_var_printf *var,
		va_list ap)
{
	if ((var->str = ft_strdup(format)) == NULL)
		exit(-1);
	var->temp2 = var->str;
	var->temp = ft_strchr(var->str, '%');
	if (var->temp == NULL)
		ft_printf_putstr_ret(var->str, var);
	else
	{
		var->temp[0] = '\0';
		ft_printf_putstr_ret(var->str, var);
		var->temp[0] = '%';
		var->str = var->temp + 1;
		ft_printf_format_analyze(var, ap);
		while (var->str[0])
			ft_printf_format_analyze(var, ap);
	}
	free(var->conv_wspace);
	free(var->conv_wzero);
	free(var->temp2);
}
