/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:05:00 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 16:19:32 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		get_asm_index(t_env *e)
{
	int			i;
	size_t		ret;

	i = 0;
	ret = 0;
	while (e->s_file[i])
	{
		if (e->s_file[i] == '"')
		{
			ret++;
			if (ret == 4)
			{
				while (e->s_file[i] && e->s_file[i] != '\n')
				{
					if (e->s_file[i + 1] == '\n')
						return (i += 2);
					i++;
				}
			}
		}
		i++;
	}
	if (ret < 4)
		return (-2);
	return (-1);
}

static void		save_asm(t_env *e)
{
	char		*line;
	char		*trim;
	int			offset;
	size_t		i;

	i = 0;
	if (!(e->a_file = (char**)malloc(sizeof(char*) * (e->lines + 1))))
		print_error("malloc: asm: save_asm", NULL);
	while (get_next_line(e->fd_src, &line))
	{
		if (!(trim = ft_strtrim(line)))
			print_error("malloc: asm: save_asm", NULL);
		if (ft_strcmp(trim, "") && trim[0] != '#' && trim[0] != ';')
		{
			if ((offset = strchr_comment(trim)) > 0)
				e->a_file[i++] = ft_strsub(trim, 0, offset);
			else
				e->a_file[i++] = ft_strdup(trim);
		}
		ft_strdel(&line);
		ft_strdel(&trim);
	}
	e->a_file[i] = NULL;
	ft_strdel(&line);
}

void			save_file(t_env *e)
{
	size_t		i;
	int			offset;
	char		c;

	i = 0;
	if (!(e->s_file = (char*)malloc(sizeof(char) * (e->filesize + 1))))
		print_error("malloc: asm: save_file", NULL);
	if (read(e->fd_src, e->s_file, e->filesize) <= 0)
		print_error("Error reading file", NULL);
	if ((offset = get_asm_index(e)) == -1)
		print_error("Error: no asm code", NULL);
	if (offset == -2)
		print_error("Lexical error: name/comment", NULL);
	if (!(e->s_file = ft_realloc(e->s_file, offset)))
		print_error("malloc: asm: save_file", NULL);
	if (lseek(e->fd_src, offset, SEEK_SET) < 0)
		print_error("Error: lseek", NULL);
	while (read(e->fd_src, &c, 1))
	{
		if (c == '\n')
			e->lines++;
	}
	if (lseek(e->fd_src, offset, SEEK_SET) < 0)
		print_error("Error: lseek", NULL);
	save_asm(e);
}

void			open_file(char *arg, t_env *e)
{
	e->lines = 0;
	if ((e->fd_src = open(arg, O_RDONLY)) < 0)
		print_error("Error opening file", NULL);
	if ((e->filesize = lseek(e->fd_src, 0, SEEK_END)) < 0)
		print_error("Error: lseek", NULL);
	if (e->filesize == 0)
		print_error("Error: empty file", NULL);
	if (lseek(e->fd_src, 0, SEEK_SET) < 0)
		print_error("Error: lseek", NULL);
}
