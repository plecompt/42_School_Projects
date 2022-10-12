/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 11:52:49 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_funct	ft_printf_fill_tab(void (*function)(t_var_printf *var,
			va_list ap), char k)
{
	t_funct	tab;

	tab.function = function;
	tab.key = k;
	return (tab);
}

t_funct	*ft_printf_make_tab(void)
{
	static t_funct	tab[15];

	tab[0] = ft_printf_fill_tab(&ft_printf_conv_s, 's');
	tab[1] = ft_printf_fill_tab(&ft_printf_conv_min_s_l, 'S');
	tab[2] = ft_printf_fill_tab(&ft_printf_conv_p, 'p');
	tab[3] = ft_printf_fill_tab(&ft_printf_conv_d, 'd');
	tab[4] = ft_printf_fill_tab(&ft_printf_conv_min_d_l, 'D');
	tab[5] = ft_printf_fill_tab(&ft_printf_conv_d, 'i');
	tab[6] = ft_printf_fill_tab(&ft_printf_conv_o, 'o');
	tab[7] = ft_printf_fill_tab(&ft_printf_conv_min_o_l, 'O');
	tab[8] = ft_printf_fill_tab(&ft_printf_conv_u, 'u');
	tab[9] = ft_printf_fill_tab(&ft_printf_conv_min_u_l, 'U');
	tab[10] = ft_printf_fill_tab(&ft_printf_conv_x_1, 'x');
	tab[11] = ft_printf_fill_tab(&ft_printf_conv_x_2, 'X');
	tab[12] = ft_printf_fill_tab(&ft_printf_conv_c, 'c');
	tab[13] = ft_printf_fill_tab(&ft_printf_conv_min_c_l, 'C');
	tab[14] = ft_printf_fill_tab(NULL, -1);
	return (tab);
}

void	ft_printf_spec_id(t_var_printf *var, va_list ap)
{
	t_funct	*tab;

	tab = ft_printf_make_tab();
	while (tab[var->t].key != -1)
	{
		if (tab[var->t].key == var->spec)
		{
			tab[var->t].function(var, ap);
			var->conv = 1;
		}
		var->t++;
	}
	if (!var->conv)
		ft_printf_no_conv(var);
}
