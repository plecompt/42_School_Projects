/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:56:58 by plecompt          #+#    #+#             */
/*   Updated: 2016/04/04 14:59:34 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write (1, &c, 1);
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int		ft_atoi(char *str)
{
	int i = 0;
	int nbr = 0;
	int negative = 0;

	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

int		ft_add(int	nb)
{
	static int somme = 0;
	int i = 2; 
	int flag = 0;
	if (nb == 0)
		return (somme);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			flag=1;
		i++;
	}
		if (flag == 0 && nb != 1)
			somme += nb;
		ft_add(nb - 1);
		return (somme);
}

int main (int argc, char **argv)
{
	long int i;
	if (argc == 2)
	{
		i = ft_atoi(argv[1]);
		if (i < 0)
		{
			ft_putchar('0');
			ft_putchar('\n');
			return 0;
		}
		i = ft_add(i);
		ft_putnbr(i);
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
	return 0;
}
