/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*get_name_from_index(t_room **room_list, int index, t_env *e)
{
	if (index >= 0 && index < e->room_nb)
		return (room_list[index]->name);
	else
		return (NULL);
}

int			get_index_from_name(t_room **room_list, char *name, t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->room_nb)
	{
		if (!ft_strcmp(room_list[i]->name, name))
			return (i);
	}
	return (-1);
}

float		get_distance(int *coords)
{
	int		a;
	int		b;
	float	f;

	a = (coords[0] - coords[2]) * (coords[0] - coords[2]);
	b = (coords[1] - coords[3]) * (coords[1] - coords[3]);
	f = sqrt(a + b);
	return (f);
}

void		free_matrix(int **matrix, t_env *e)
{
	int i;

	i = 0;
	while (i < e->room_nb)
	{
		free(matrix[i]);
		i++;
	}
	matrix = NULL;
}

void		init_matrix(int **matrix, t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->room_nb)
	{
		j = 0;
		if (!(matrix[i] = malloc(sizeof(int) * e->room_nb)))
			return ;
		while (j < e->room_nb)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}
