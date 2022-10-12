/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 08:36:46 by plecompt          #+#    #+#             */
/*   Updated: 2015/02/11 12:12:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_color(char *str, int color, int out)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_color(str[i], color, out);
		i++;
	}
}
