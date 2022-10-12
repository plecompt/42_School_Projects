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

void		ft_putchar_color(char c, int color, int out)
{
	if (color == 1)
		write(out, RED, 7);
	if (color == 2)
		write(out, GREEN, 7);
	if (color == 3)
		write(out, YELLOW, 7);
	if (color == 4)
		write(out, BLUE, 7);
	if (color == 5)
		write(out, PURPLE, 7);
	if (color == 6)
		write(out, CYAN, 7);
	if (color == 7)
		write(out, GREY, 7);
	if (color == 8)
		write(out, BLACK, 7);
	write(out, &c, 1);
	write(out, RESET, 5);
}
