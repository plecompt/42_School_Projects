/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:47:05 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:47:07 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_unbrlen_base(unsigned long long int nb, unsigned int base)
{
	size_t	ret;

	ret = 0;
	while (nb >= base)
	{
		nb /= base;
		ret++;
	}
	ret++;
	return (ret);
}
