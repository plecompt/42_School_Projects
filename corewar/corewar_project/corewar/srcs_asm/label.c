/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/14 11:03:33 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_count_label_approx(t_env *e, int nb_instruction)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < nb_instruction)
	{
		while (e->a_file[i][j])
		{
			if (e->a_file[i][j] == ':')
				e->nb_of_label++;
			j++;
		}
		i++;
		j = 0;
	}
}

int		ft_is_label(char *str)
{
	int i;

	i = ft_strlen(str);
	if (str[i - 1] == ':')
		return (1);
	else
		return (0);
}

int		ft_sum_of_size(t_env *e, int offset)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i != offset)
	{
		if (e->tab_instruction[i][1] == 2)
			sum += 4;
		if (e->tab_instruction[i][1] == 1)
			sum += 2;
		if (e->tab_instruction[i][1] == 0)
			sum += 1;
		i++;
	}
	return (sum);
}

void	ft_label_sneak(t_env *e, char *label_name, int nb_o, int *opcode_pos)
{
	static int	i = 0;
	int			opcode;
	int			pos;

	opcode = opcode_pos[0];
	pos = 1 - opcode_pos[1];
	e->label_sneak[i] = ft_strdup(label_name);
	e->label_offset_sneak[i][0] = e->offset;
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
		e->label_offset_sneak[i][1] = ft_sum_of_size(e, e->offset);
	else
		e->label_offset_sneak[i][1] = ft_sum_of_size(e, e->offset + pos) - 1;
	e->tab_instruction[e->offset][1] = nb_o;
	i++;
	e->nb_of_label_call++;
}

void	ft_add_label(t_env *e, char *label_name)
{
	int i;

	i = 0;
	while (i < e->nb_of_label)
	{
		if (e->nb_of_label > 1 && ft_strcmp(e->label[i], label_name) == 0)
			e->nb_of_label -= 1;
		else
		{
			e->label[e->nb_of_label - 1] = ft_strdup(label_name);
			e->label[e->nb_of_label - 1][ft_strlen(label_name) - 1] = '\0';
			e->label_offset[e->nb_of_label - 1] = e->offset;
			return ;
		}
		i++;
	}
}
