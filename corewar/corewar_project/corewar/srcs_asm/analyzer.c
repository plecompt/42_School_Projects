/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:08:21 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/14 10:35:07 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_creat_ocp(t_env *e, char **tmp, int index)
{
	int				i;
	int				result_wich_k;
	int				nb_elem_to_check;
	unsigned char	ret;

	ret = 0;
	nb_elem_to_check = how_many_elem(tmp[index]);
	i = 0;
	while (i < 3)
	{
		if (i < nb_elem_to_check)
			result_wich_k = which_kind(tmp[index + 1 + i]);
		if (i < nb_elem_to_check && result_wich_k == 1)
			ret = ret | 1;
		else if (i < nb_elem_to_check && (result_wich_k == 2 ||
			result_wich_k == 4))
			ret = ret | 2;
		else if (i < nb_elem_to_check && (result_wich_k == 3 ||
			result_wich_k == 5))
			ret = ret | 3;
		ret = ret << 2;
		i += 1;
	}
	e->tab_instruction[e->offset][0] = ret;
	e->offset++;
}

static void		condition_two(t_env *e, char **tmp, int index, int *opcode_pos)
{
	if (which_op(tmp[index]) == 3 || which_op(tmp[index]) == 9 ||
		which_op(tmp[index]) == 10 || which_op(tmp[index]) == 11 ||
		which_op(tmp[index]) == 12 || which_op(tmp[index]) == 14 ||
		which_op(tmp[index]) == 15)
	{
		if (which_kind(tmp[index + 1 + e->i]) == 2)
		{
			e->tab_instruction[e->offset][0] =
				ft_atoi(tmp[index + 1 + e->i] + 1);
			e->tab_instruction[e->offset][1] = 1;
		}
		if (which_kind(tmp[index + 1 + e->i]) == 4)
			ft_label_sneak(e, tmp[index + 1 + e->i] + 2, 1, opcode_pos);
		if (which_kind(tmp[index + 1 + e->i]) == 5)
			ft_label_sneak(e, tmp[index + 1 + e->i] + 1, 1, opcode_pos);
	}
}

static void		condition_one(t_env *e, char **tmp, int index, int *opcode_pos)
{
	if (which_op(tmp[index]) == 1 || which_op(tmp[index]) == 2 ||
		which_op(tmp[index]) == 6 || which_op(tmp[index]) == 7 ||
		which_op(tmp[index]) == 8 || which_op(tmp[index]) == 13)
	{
		if (which_kind(tmp[index + e->i + 1]) == 2)
		{
			e->tab_instruction[e->offset][0] =
				ft_atoi(tmp[index + 1 + e->i] + 1);
			e->tab_instruction[e->offset][1] = 2;
		}
		if (which_kind(tmp[index + 1 + e->i]) == 4)
			ft_label_sneak(e, tmp[index + 1 + e->i] + 2, 2, opcode_pos);
		if (which_kind(tmp[index + 1 + e->i]) == 5)
			ft_label_sneak(e, tmp[index + 1 + e->i] + 1, 1, opcode_pos);
	}
}

static void		ft_ocp(t_env *e, char **tmp, int index)
{
	if ((e->tab_instruction[e->offset - 1][0] != 1) &&
	(e->tab_instruction[e->offset - 1][0] != 9) &&
	(e->tab_instruction[e->offset - 1][0] != 12) &&
	(e->tab_instruction[e->offset - 1][0] != 15))
		ft_creat_ocp(e, tmp, index);
}

void			ft_analyzer(t_env *e, char **tmp, int index)
{
	int opcode_position[2];
	int nb_elem_to_add;

	e->i = 0;
	e->tab_instruction[e->offset][0] = which_op(tmp[index]);
	e->offset += 1;
	ft_ocp(e, tmp, index);
	nb_elem_to_add = how_many_elem(tmp[index]);
	while (e->i < nb_elem_to_add)
	{
		opcode_position[0] = which_op(tmp[index]);
		opcode_position[1] = e->i + 1;
		if (which_kind(tmp[index + 1 + e->i]) == 1)
			e->tab_instruction[e->offset][0] =
			ft_atoi(tmp[index + 1 + e->i] + 1);
		else if (which_kind(tmp[index + 1 + e->i]) == 3)
		{
			e->tab_instruction[e->offset][0] = ft_atoi(tmp[index + 1 + e->i]);
			e->tab_instruction[e->offset][1] = 1;
		}
		condition_one(e, tmp, index, opcode_position);
		condition_two(e, tmp, index, opcode_position);
		e->offset++;
		e->i++;
	}
}
