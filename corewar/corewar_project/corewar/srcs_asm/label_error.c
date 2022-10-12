/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:21:18 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 17:11:43 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			del_label(t_env *e, char *substr, int start, int i)
{
	char			tmp[ft_strlen(e->a_file[i])];

	ft_bzero(tmp, ft_strlen(e->a_file[i]));
	if (e->label_flag)
	{
		ft_strncat(tmp, e->a_file[i], start);
		ft_strcat(tmp, &e->a_file[i][start + ft_strlen(substr) + 1]);
		if (!(e->a_tmp[i] = ft_strtrim(tmp)))
			print_error("malloc: asm: del_label", NULL);
	}
	else if (!(e->a_tmp[i] = ft_strtrim(e->a_file[i])))
		print_error("malloc: asm: del_label", NULL);
	e->label_flag = false;
}

static void			check_label_chars(char *label)
{
	int				i;

	i = 0;
	while (label[i])
	{
		if (!ft_strchr(LABEL_CHARS, label[i]))
			print_error("Lexical error: not a valid label", label);
		i++;
	}
}

static void			sub_label(t_env *e, int i, int j, int start)
{
	char			*label;

	label = ft_strsub(e->a_file[i], start, j - start);
	if (e->a_file[i][j] == LABEL_CHAR)
	{
		check_label_chars(label);
		list_push_back(e->labels, label);
		e->label_flag = true;
	}
	del_label(e, label, start, i);
	ft_strdel(&label);
}

void				check_label(t_env *e)
{
	int				i;
	int				j;
	int				start;

	i = 0;
	e->labels = create_list();
	while (e->a_file[i])
	{
		start = 0;
		j = 0;
		while (e->a_file[i][j] && \
		(e->a_file[i][j] == ' ' || e->a_file[i][j] == '\t'))
			j++;
		start = j;
		while (e->a_file[i][j] && e->a_file[i][j] != LABEL_CHAR && \
		e->a_file[i][j] != ' ' && e->a_file[i][j] != '\t')
			j++;
		sub_label(e, i, j, start);
		i++;
	}
}
