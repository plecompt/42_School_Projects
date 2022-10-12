/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:19:37 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/03 11:19:43 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_nbrlen_base(long long int nb, int base)
{
	size_t	ret;

	ret = 0;
	if ((nb < 0) && (nb <= -base))
	{
		nb = nb / -base;
		ret++;
	}
	while (nb >= base)
	{
		nb = nb / base;
		ret++;
	}
	ret++;
	return (ret);
}
