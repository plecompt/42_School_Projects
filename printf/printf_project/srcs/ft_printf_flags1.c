/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:58:29 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:18:54 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_is_flag(char c)
{
	return (c == '#' || c == '-' || c == '+' || c == ' ' ||
			c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
			c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ||
			c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '.');
}

int		ft_printf_find_num(t_var_printf *var)
{
	if (ft_isdigit(var->str[0]))
	{
		if ((var->str[0] == '0') && (!ft_isdigit(var->str[-1])))
		{
			var->zero = 1;
			return (0);
		}
		if (var->size_min != 0)
			var->size_min = 0;
		while (ft_isdigit(var->str[0]))
		{
			var->size_min = var->size_min * 10 + var->str[0] - '0';
			var->str = var->str + 1;
		}
		return (1);
	}
	return (0);
}

int		ft_printf_find_prec(t_var_printf *var)
{
	if (var->str[0] == '.')
	{
		while (var->str[0] == '.')
			var->str = var->str + 1;
		var->have_pres = 1;
		if (ft_isdigit(var->str[0]))
		{
			if (var->pres != 0)
				var->pres = 0;
			while (ft_isdigit(var->str[0]))
			{
				var->pres = var->pres * 10 + var->str[0] - '0';
				var->str = var->str + 1;
			}
			return (1);
		}
		return (1);
	}
	return (0);
}

void	ft_printf_find_l_end_h(t_var_printf *var)
{
	if (var->str[0] == 'l')
	{
		if (var->str[1] == 'l')
		{
			var->ll = 1;
			var->str = var->str + 1;
		}
		else
			var->l = 1;
	}
	if (var->str[0] == 'h')
	{
		if (var->str[1] == 'h')
		{
			var->hh = 1;
			var->str = var->str + 1;
		}
		else
			var->h = 1;
	}
}

void	ft_printf_find_flag(t_var_printf *var)
{
	while (ft_printf_is_flag(var->str[0]))
	{
		ft_printf_find_l_end_h(var);
		if (var->str[0] == '#')
			var->sharp = 1;
		else if (var->str[0] == '-')
			var->minus = 1;
		else if (var->str[0] == '+')
			var->plus = 1;
		else if (var->str[0] == ' ')
			var->space = 1;
		else if (var->str[0] == 'j')
			var->j = 1;
		else if (var->str[0] == 'z')
			var->z = 1;
		if ((!ft_printf_find_prec(var)) && (!ft_printf_find_num(var)))
			var->str = var->str + 1;
	}
}
