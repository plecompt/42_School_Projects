/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 16:37:47 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/23 16:38:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_operation(int a, int b, char *c)
{
    if (c[0] == '+')
        printf("%d\n", (a + b));
    else if (c[0] == '-')
        printf("%d\n", (a - b));
    else if (c[0] == '%')
        printf("%d\n", (a % b));
    else if (c[0] == '/')
        printf("%d\n", (a / b));
    else if (c[0] == '*')
        printf("%d\n", (a * b));
}

int main(int ac, char **av)
{
    int a = 0;
    int b = 0;
    if (ac == 4)
    {
        if (!av[1] || !av[2] || !av[3])
        {
            ft_putchar('\n');
            return (0);
        }
		a = atoi(av[1]);
		b = atoi(av[3]);
        ft_operation(a, b, av[2]);
    }
    else
        ft_putchar('\n');
    return (0);
}
