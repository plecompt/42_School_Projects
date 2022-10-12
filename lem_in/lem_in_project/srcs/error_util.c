/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long int		ft_latoi(const char *str)
{
	int				sign;
	long int		nb;

	sign = 1;
	nb = 0;
	if (ft_strlen(str) > 10)
		print_error("Error: invalid number of ant");
	while (*str == ' ' || *str == '\n' || *str == '\v'
			|| *str == '\t' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (sign * nb);
}

int				ft_is_dup(t_slist *list)
{
	t_line		*tmp;
	t_line		*tmp2;

	tmp = list->head;
	while (tmp && tmp->next)
	{
		tmp2 = tmp;
		while (tmp2->next)
		{
			if (!ft_strcmp(tmp->data, tmp2->next->data))
				return (TRUE);
			else
				tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

int				ft_isnumber(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
