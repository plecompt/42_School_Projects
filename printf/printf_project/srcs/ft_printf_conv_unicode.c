/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_unicode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:59:32 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:06:10 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv_unicode(t_var_printf *var)
{
	if (var->wchar < 0x80)
		var->conv_temp[0] = ((var->wchar >> 0) & 0x7F) | 0x00;
	else if (var->wchar < 0x0800)
	{
		var->conv_temp[0] = ((var->wchar >> 6) & 0x1F) | 0xC0;
		var->conv_temp[1] = ((var->wchar >> 0) & 0x3F) | 0x80;
	}
	else if (var->wchar < 0x010000)
	{
		var->conv_temp[0] = ((var->wchar >> 12) & 0x0F) | 0xE0;
		var->conv_temp[1] = ((var->wchar >> 6) & 0x3F) | 0x80;
		var->conv_temp[2] = ((var->wchar >> 0) & 0x3F) | 0x80;
	}
	else if (var->wchar < 0x110000)
	{
		var->conv_temp[0] = ((var->wchar >> 18) & 0x07) | 0xF0;
		var->conv_temp[1] = ((var->wchar >> 12) & 0x3F) | 0x80;
		var->conv_temp[2] = ((var->wchar >> 6) & 0x3F) | 0x80;
		var->conv_temp[3] = ((var->wchar >> 0) & 0x3F) | 0x80;
	}
}
