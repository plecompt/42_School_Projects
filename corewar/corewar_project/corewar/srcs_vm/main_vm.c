/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:03:12 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 19:03:26 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_vm	g_vm;

int		main(int ac, char **av)
{
	if (ac < 2)
		error(NULL, NULL);
	ft_bzero(&g_vm, sizeof(g_vm));
	ft_bzero(&g_vm.option, sizeof(g_vm.option));
	g_vm.option.dump_cycle = -1;
	parse_vm(ac - 1, &av[1], &g_vm.option);
	lunch_vm();
	return (0);
}
