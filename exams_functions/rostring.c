/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:57:14 by exam              #+#    #+#             */
/*   Updated: 2016/04/19 11:33:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void		ft_putchar(char c)
{
	write (1, &c, 1);
}

void		ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_putstr_middle(char *str, int i)
{
	while (str[i])
	{
		ft_putchar(str[i]);
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r') && (str[i + 1] == ' ' || str[i + 1] == '\t'
				|| str[i + 1] == '\r'))
			i++;
		i++;
	}
}

void		rotstring(char *str)
{
	int i = 0;
	int len = 0;
	int debut = 0;
	int x = 0;
	char *last;

	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r') && (str[i]))
		i++;
	debut = i;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i])
	{
		len++;
		i++;
	}
	if (!(last = (char *)malloc(sizeof(char) * len + 1)))
		return ;
	while (len)
	{
		last[x] = str[debut];
		x++;
		debut++;
		len--;
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i])
	{
		ft_putstr_middle(str, i);
		write (1, " ", 1);
		ft_putstr(last);
	}
	else
		ft_putstr(last);
}

int main (int argc, char **argv)
{
	if (argc > 1)
		rotstring(argv[1]);
	write (1, "\n", 1);
	return 0;
}
	

