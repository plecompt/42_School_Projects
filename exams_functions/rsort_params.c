/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsort_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 13:59:37 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/10 10:37:46 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		my_putendl(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int			ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void		rsort_param(char **tab, int size)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) < 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	i = -1;
	while (++i < size)
		my_putendl(tab[i]);
}

int			main(int ac, char **av)
{
	if (ac > 1)
		rsort_param(&av[1], ac - 1);
	else
		write(1, "\n", 1);
	return (0);
}
