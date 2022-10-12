/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:41:09 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/17 12:36:48 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int i;
	int tab[256];
	char *tmp;

	tmp = NULL;
	i = -1;
	tmp = s2;
	while (++i < 256)
		tab[i] = 0;
	while (*s1)
	{
		while (*s2)
		{
			if (*s1 == *s2 && tab[(int)*s1] != 1)
			{
				tab[(int)*s1] = 1;
				write(1, s1, 1);
			}
			s2++;
		}
		s1++;
		s2 = tmp;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
