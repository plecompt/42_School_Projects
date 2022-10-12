/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/14 14:14:05 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_traduct_this_line(t_env *e, char *line)
{
	char **tmp;

	tmp = ft_stronesplit(line, ' ');
	if (!tmp[1])
	{
		e->nb_of_label += 1;
		ft_add_label(e, tmp[0]);
	}
	else if (ft_is_label(tmp[0]) == 1)
	{
		e->nb_of_label += 1;
		ft_add_label(e, tmp[0]);
		ft_analyzer(e, tmp, 1);
	}
	else
		ft_analyzer(e, tmp, 0);
	ft_arrdel(tmp);
}

static void		ft_to_int_tab(t_env *e, int nb_instruction)
{
	int i;

	i = 0;
	e->offset = 0;
	e->nb_of_label = 0;
	e->nb_of_label_call = 0;
	e->nb_instruction = nb_instruction * 8;
	ft_count_label_approx(e, nb_instruction);
	ft_init_tab(e, e->nb_instruction);
	if (e->nb_of_label)
		ft_init_label_env(e, e->nb_of_label);
	e->nb_of_label = 0;
	e->off_limit[i] = e->offset;
	while (i < nb_instruction)
	{
		ft_traduct_this_line(e, e->a_file[i]);
		i++;
		e->off_limit[i] = e->offset;
	}
}

static void		ft_sneak_write(t_env *e)
{
	int offset_trouve;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->nb_of_label_call)
	{
		while (j < e->nb_of_label)
		{
			if (ft_strcmp(e->label[j], e->label_sneak[i]) == 0)
			{
				offset_trouve = ft_sum_of_size(e, e->label_offset[j]) -
					e->label_offset_sneak[i][1];
				break ;
			}
			j++;
		}
		e->tab_instruction[e->label_offset_sneak[i][0]][0] = offset_trouve + 1;
		j = 0;
		i++;
	}
}

void			run_encoder(t_env *e)
{
	char	*tmp;
	int		i;

	i = 0;
	while (e->a_file[i])
	{
		ft_epur_from_comma(e, ',', i);
		tmp = epur_str(e->a_file[i]);
		ft_strcpy(e->a_file[i], tmp);
		free(tmp);
		i++;
	}
	ft_to_int_tab(e, i);
	ft_sneak_write(e);
}
