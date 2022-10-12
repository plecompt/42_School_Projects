/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/10 15:34:41 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_init_tab(t_env *e, int nb_instruction)
{
	int i;

	if (!(e->off_limit = (int *)malloc(sizeof(int) * (nb_instruction / 4))))
		print_error("malloc: asm: ft_init_tab", NULL);
	if (!(e->tab_instruction = (int **)malloc(sizeof(int *) * nb_instruction)))
		print_error("malloc: asm: ft_init_tab", NULL);
	i = 0;
	while (i < nb_instruction)
	{
		if (!(e->tab_instruction[i] = (int *)malloc(sizeof(int) * 2)))
			print_error("malloc: asm: ft_init_tab", NULL);
		e->tab_instruction[i][0] = 0;
		e->tab_instruction[i][1] = 0;
		i++;
	}
}

void	ft_init_label_env(t_env *e, int nb_of_label)
{
	int i;

	i = 0;
	if (!(e->label = (char **)malloc(sizeof(char *) * nb_of_label)))
		print_error("malloc: asm: ft_init_label_env", NULL);
	if (!(e->label_sneak = (char **)malloc(sizeof(char *) * nb_of_label)))
		print_error("malloc: asm: ft_init_label_env", NULL);
	if (!(e->label_offset = (int *)malloc(sizeof(int) * nb_of_label)))
		print_error("malloc: asm: ft_init_label_env", NULL);
	if (!(e->label_offset_sneak = (int **)malloc(sizeof(int*) * nb_of_label)))
		print_error("malloc: asm: ft_init_label_env", NULL);
	while (i < nb_of_label)
	{
		e->label_offset[i] = 0;
		if (!(e->label_offset_sneak[i] = (int *)malloc(sizeof(int) * 2)))
			print_error("malloc: asm: ft_init_label_env", NULL);
		e->label_offset_sneak[i][0] = 0;
		e->label_offset_sneak[i][1] = 0;
		i++;
	}
}
