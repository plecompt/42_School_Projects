/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:47:43 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 14:27:11 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		usage(void)
{
	ft_printf("Usage: ./corewar [-option (NUMBER)] <champion1.cor> <...>\n");
	ft_printf("\t-a: Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("\t-d N: Dumps memory after N cycles then exits\n");
	ft_printf("\t-s N: Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_printf("\t-n N: Fix number of player\n");
	ft_printf("\t-v: Show verbose mode\n");
	exit(1);
}

void			error(char *file, char *str)
{
	if (file == NULL && str == NULL)
		usage();
	ft_printf("Error :\n\t");
	ft_printf("%s : %s\n", file, str);
	exit(1);
}
