/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:01 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 15:54:02 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				print_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

static void		error_handling2(char *line, char *tmp, char **arr, t_env *e)
{
	if (tmp != NULL && (!ft_strcmp(tmp, "##start") || !ft_strcmp(tmp, "##end")))
	{
		arr = ft_strsplit(line, ' ');
		if (ft_arrlen(arr) != 3)
			print_error("Error: invalid room");
		if (!ft_isnumber(arr[1]) || !ft_isnumber(arr[2]))
			print_error("Error: invalid room");
		if (!ft_strcmp(tmp, "##start"))
			e->start_name = ft_strdup(arr[0]);
		else
			e->end_name = ft_strdup(arr[0]);
		ft_arrdel(arr);
	}
}

void			error_handling(char *line, char *tmp, int index, t_env *e)
{
	char		**arr;

	if (index == 0 && (!ft_isnumber(line) || \
	ft_latoi(line) == 0 || ft_latoi(line) > MAX_INT))
		print_error("Error: invalid number of ant");
	if (index == 0 && ft_isnumber(line))
		e->ants = ft_atoi(line);
	arr = ft_strsplit(line, '-');
	if (ft_arrlen(arr) == 2)
	{
		e->is_pipe = TRUE;
		e->nb_pipe++;
	}
	if (!ft_strcmp(line, "##start"))
		e->is_start = TRUE;
	if (!ft_strcmp(line, "##end"))
		e->is_end = TRUE;
	ft_arrdel(arr);
	error_handling2(line, tmp, arr, e);
}
