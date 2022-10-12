/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:54:55 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/14 12:21:53 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insertion_sort(int *tab, size_t size)
{
	int i;
	int	j;
	int elem;

	i = 0;
	while (i < (int)size)
	{
		elem = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > elem)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = elem;
		i++;
	}
}
