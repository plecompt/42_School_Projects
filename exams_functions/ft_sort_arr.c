/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 09:37:21 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/03 13:10:14 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <assert.h>

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void		ft_sort_arr(char **tab, int size)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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
	char	*tab[4];

	tab[0] = strdup("aaa");
	tab[1] = strdup("az");
	tab[2] = strdup("abc");
	tab[3] = strdup("Abc");

	ft_sort_arr(tab, 4);

	assert(strcmp(tab[0], "Abc") == 0);
	assert(strcmp(tab[1], "aaa") == 0);
	assert(strcmp(tab[2], "abc") == 0);
	assert(strcmp(tab[3], "az") == 0);
	printf("ft_sort_arr OK!\n");
	return (0);
}
