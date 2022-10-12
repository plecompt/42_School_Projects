/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:24:45 by hivian            #+#    #+#             */
/*   Updated: 2017/04/25 12:06:52 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void		handle_overflow(int sign, long int nb, const char *str)
{
	char		*tmp;

	tmp = ft_litoa(sign * nb);
	if (!ft_strequ(tmp, str))
	{
		ft_strdel(&tmp);
		ft_printf("Syntax error: overflow: \"%s\"\n", str);
		exit(EXIT_FAILURE);
	}
	ft_strdel(&tmp);
}

long int		ft_latoi(const char *str)
{
	int			sign;
	long int	nb;
	int			i;

	sign = 1;
	nb = 0;
	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v'
			|| *str == '\t' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		i++;
	}
	else if (*str == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	handle_overflow(sign, nb, str);
	return (sign * nb);
}
