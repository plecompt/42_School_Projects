/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:45:20 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 15:47:17 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char			*strendchr(const char *s)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t')
		len--;
	if (s[len - 1] == '\n')
		return ((char*)(s) + i);
	return (NULL);
}

void				check_tag(char *tag)
{
	static bool		is_name = false;
	static bool		is_comment = false;
	char			*tmp;

	if (strendchr(tag))
		print_error("Syntax error: incorrect separation", NULL);
	if (!(tmp = ft_strtrim(tag)))
		print_error("malloc: asm: check_tag", NULL);
	if (ft_strequ(tmp, NAME_CMD_STRING) && is_name)
		print_error("Syntax error: duplicate", tmp);
	if (ft_strequ(tmp, COMMENT_CMD_STRING) && is_comment)
		print_error("Syntax error: duplicate", tmp);
	if (ft_strequ(tmp, NAME_CMD_STRING))
		is_name = true;
	else if (ft_strequ(tmp, COMMENT_CMD_STRING))
		is_comment = true;
	else
		print_error("Lexical error: name/comment", NULL);
	ft_strdel(&tmp);
}

void				check_n_c(t_env *e, char *str, char *tag)
{
	char			*tmp;

	if (!(tmp = ft_strtrim(tag)))
		print_error("malloc: asm: check_n_c", NULL);
	if (ft_strequ(tmp, NAME_CMD_STRING) && \
	ft_strlen(str) - 2 > PROG_NAME_LENGTH)
		print_error("Lexical error: champion name too long", NULL);
	else if (ft_strequ(tmp, COMMENT_CMD_STRING) \
	&& ft_strlen(str) - 2 > COMMENT_LENGTH)
		print_error("Lexical error: comment too long", NULL);
	if (ft_strequ(tmp, NAME_CMD_STRING))
		e->dot_name = trim_quotes(str);
	else if (ft_strequ(tmp, COMMENT_CMD_STRING))
		e->dot_comment = trim_quotes(str);
	ft_strdel(&tmp);
}

static void			del_sub(t_env *e, char *substr, int start)
{
	char			*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(e->s_file) + 1)))
		print_error("malloc: asm: del_sub", NULL);
	ft_bzero(tmp, ft_strlen(e->s_file) + 1);
	ft_strncpy(tmp, e->s_file, start);
	ft_strcat(tmp, &e->s_file[start + ft_strlen(substr)]);
	ft_strdel(&e->s_file);
	if (!(e->s_file = ft_realloc(tmp, ft_strlen(tmp))))
		print_error("malloc: asm: del_sub", NULL);
}

void				remove_comments(t_env *e)
{
	size_t			i;
	size_t			start;
	size_t			quotes;
	char			*tmp;

	i = 0;
	quotes = 0;
	while (e->s_file[i])
	{
		if (e->s_file[i] == '"')
			quotes++;
		if ((e->s_file[i] == ';' || e->s_file[i] == '#') && quotes % 2 == 0)
		{
			start = i;
			while (e->s_file[i] && e->s_file[i] != '\n')
				i++;
			if (!(tmp = ft_strsub(e->s_file, start, i - start)))
				print_error("malloc: asm: remove_comments", NULL);
			del_sub(e, tmp, start);
			i = start - 1;
			ft_strdel(&tmp);
		}
		i++;
	}
}
