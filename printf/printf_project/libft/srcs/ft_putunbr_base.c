/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:45:11 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:45:12 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putunbr_base(unsigned long long int nb, char *str_base)
{
	unsigned int	base;

	base = (unsigned int)ft_strlen(str_base);
	if (nb >= base)
	{
		ft_putunbr_base(nb / base, str_base);
		ft_putunbr_base(nb % base, str_base);
	}
	else
		ft_putchar(str_base[nb]);
}
