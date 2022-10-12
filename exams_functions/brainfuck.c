/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:36:40 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/10 16:36:44 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *ret(char *str, int way)
{
	int i = 0;
	while (*str)
	{
		if (*str == '[')
			i++;
		else if (*str == ']')
			i--;
		if (i == 0)
			return (str);
		str += way;
	}
	return 0;
}

void brainfuck(char *str, unsigned char *buff)
{
	if (*str == '\0')
		return ;
	else if (*str == '+')
		(*buff)++;
	else if (*str == '-')
		(*buff)--;
	else if (*str == '>')
		buff++;
	else if (*str == '<')
		buff--;
	else if (*str == '.')
		write (1, buff, 1);
	else if (*str == '[' && buff == 0)
		str = ret(str, 1);
	else if (*str == ']' && buff != 0)
		str = ret(str, -1);
	brainfuck(str + 1, buff);
}

int main(int ac, char **av)
{
	if (ac <  1)
	{
		int i = -1;
		unsigned char buff[2048];
		while (++i < 2048)
			buff[i] = 0;
		brainfuck(av[1], buff);
		return 0;
	}
	write (1, "\n", 1);
	return 0;
}