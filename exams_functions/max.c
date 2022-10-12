/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 15:41:46 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/23 17:18:16 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			max(int* tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 0;
	max = 0;
	if (!tab)
		return (0);
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int main()
{
	int tab[5] = {200, 100, 150, -300, 6};

	printf("%d\n", max(tab, 5));
	return (0);
}
