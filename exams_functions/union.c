/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 13:38:08 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/17 12:42:42 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *s1, char *s2, int *tab)
{
	while (*s1)
	{
		if (tab[(int)*s1] == 0)
		{
			tab[(int)*s1] = 1;
			write(1, s1, 1);
		}
		s1++;
	}
	while (*s2)
	{
		if (tab[(int)*s2] == 0)
		{
			tab[(int)*s2] = 1;
			write(1, s2, 1);
		}
		s2++;
	}
}

void	ft_union(char *s1, char *s2)
{
	int tab[256];
	int i;

	i = -1;
	while (++i < 256)
		tab[i] = 0;
	ft_print(s1, s2, tab);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
