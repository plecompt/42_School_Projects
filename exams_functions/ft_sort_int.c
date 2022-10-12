/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 09:20:13 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/03 13:12:56 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>

void		ft_sort_int(int *tab, int size)
{
	int		tmp;
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int			main(void)
{
	int		tab[6] = {8, 6, 0, -15, 42, 21};

	ft_sort_int(tab, 6);
	assert(tab[0] == -15);
	assert(tab[1] == 0);
	assert(tab[2] == 6);
	assert(tab[3] == 8);
	assert(tab[4] == 21);
	assert(tab[5] == 42);
	printf("ft_sort_int OK!\n");
	return (0);
}
