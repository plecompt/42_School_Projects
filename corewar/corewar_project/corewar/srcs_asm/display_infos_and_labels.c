/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_infos_and_labels.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/15 11:22:19 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_display_informations(t_env *e)
{
	ft_printf("Nom du programme: %s\n", e->dot_name);
	ft_printf("Commentaire: %s\n", e->dot_comment);
	ft_printf("Taille du programme: %d bytes\n\n", e->progsize);
}

void	ft_display_label_list(t_env *e)
{
	int y;

	y = 0;
	ft_printf("There is %i label(s) defined:\n\n", e->nb_of_label);
	while (y < e->nb_of_label)
	{
		ft_printf("Label \033[36m%s\033[0m:\n", e->label[y]);
		ft_printf("-Offset ASM: \033[31m%i\033[0m\n", e->label_offset[y]);
		ft_printf("-Offset encodé: \033[31m%i\033[0m\n\n",
			ft_sum_of_size(e, e->label_offset[y]));
		y++;
	}
	ft_printf("\nThere is %i call(s):\n\n", e->nb_of_label_call);
	y = 0;
	while (y < e->nb_of_label_call)
	{
		ft_printf("Call \033[36m%s\033[0m:\n", e->label_sneak[y]);
		ft_printf("-Offset ASM: \033[31m%i\033[0m\n",
			e->label_offset_sneak[y][0]);
		ft_printf("-Offset calculé: \033[31m%i\033[0m\n",
			e->label_offset_sneak[y][1] - 1);
		ft_printf("-Valeur calculée: \033[31m%i\033[0m\n\n",
			e->tab_instruction[e->label_offset_sneak[y][0]][0]);
		y++;
	}
}
