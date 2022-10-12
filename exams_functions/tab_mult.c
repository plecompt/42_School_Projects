/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:04:57 by plecompt          #+#    #+#             */
/*   Updated: 2016/04/19 14:27:59 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *str)
{
	int nb = 0;
	int sign = 1;
	int i = 0;
	if (str[0] == '+')
		i++;
	else if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] == '\t' || str[i] == '\r' || str[i] == ' ') && str[i])
		i++;
	while(str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}


void	ft_tab_mult(int nb)
{
	int i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(nb);
		ft_putstr(" = ");
		ft_putnbr(i * nb);
		ft_putstr("\n");
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
		ft_tab_mult(ft_atoi(argv[1]));
	else
		write (1, "\n", 1);
	return 0;
}
