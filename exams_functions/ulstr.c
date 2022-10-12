/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:22:27 by plecompt          #+#    #+#             */
/*   Updated: 2014/12/14 08:53:16 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ulstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		my_putstr(ulstr(av[1]));
	write(1, "\n", 1);
	return (0);
}
