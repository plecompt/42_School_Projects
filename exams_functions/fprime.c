/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 14:09:15 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/27 14:52:48 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	fprime(int nb)
{
	int val = nb;
	int a = 2;
	int res = 1;

	while (res < val)
	{
		if (nb % a == 0)
		{
			printf("%d", a);
			res *= a;
			nb /= a;
			if (res != val)
				printf("*");
		}
		else
			a += 1;
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	if (ac != 2)
		printf("\n");
	else if (atoi(av[1]) == 1)
		printf("\n");
	else
		fprime(atoi(av[1]));
}
