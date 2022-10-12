/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:06:34 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/22 08:01:16 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			pgcd(int a, int b)
{
	if (a == b)
		return (a);
	return (a % b ? pgcd(b, a % b) : b);
}

int			main(void)
{
	int		res;
	int		a;
	int		b;

	a = 6;
	b = 9;

	printf("a = 6, b = 9\n");
	res = pgcd(a, b);
	printf("Result : %d\n", res);
	return (0);
}
