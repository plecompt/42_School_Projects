/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 16:15:41 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/23 17:24:31 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int	i;
	int nb;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	nb = i - 1;
	i = -1;
	while (str[++i])
	{
		if (i == nb && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if ((str[i + 1] == ' ' || str[i + 1] == '\t') && \
			 str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int		main(int ac, char **av)
{
	int	i;

	if (ac > 1)
	{
		i = 1;
		while (i != ac)
		{
			rstr_capitalizer(av[i++]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
