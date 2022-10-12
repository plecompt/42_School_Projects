/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 10:46:44 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/27 12:29:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (min < max)
		tab[i++] = min++;
	return (tab);
}

int			*ft_ranger(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (max > min)
		tab[i++] = max--;
	return (tab);
}

int			*ft_rrange(int start, int end)
{
	if (start < end)
		return (ft_ranger(start, end));
	return (ft_range(end, start));
}

int			main(void)
{
	int		min;
	int		max;
	int		i;
	int		*tab;

	i = -1;
	min = -10;
	max = 10;
	tab = ft_rrange(min, max);
	if (min < max)
	{
		while (++i < max - min)
			printf("%d\n", tab[i]);
	}
	else
	{
		while (++i < min - max)
			printf("%d\n", tab[i]);
	}
	return (0);
}
