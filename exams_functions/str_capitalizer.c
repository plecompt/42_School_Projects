/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 08:44:20 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/29 09:03:37 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		str_capitalizer(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if ((str[i] == ' ' || str[i] == '\t') && \
		str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] -= 32;
		write(1, &str[i], 1);
	}
}

int			main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i != ac)
		{
			str_capitalizer(av[i++]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
