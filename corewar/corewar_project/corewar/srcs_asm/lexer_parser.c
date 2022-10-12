/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:15:21 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 16:09:17 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			check_instr(char *line, char *name, t_env *e)
{
	if (ft_strequ(name, "live") || ft_strequ(name, "zjmp") || \
	ft_strequ(name, "fork") || ft_strequ(name, "lfork"))
		check_first(line, e);
	else if (ft_strequ(name, "aff"))
		check_aff(line);
	else if (ft_strequ(name, "and") || ft_strequ(name, "or") || \
	ft_strequ(name, "xor"))
		check_aox(line, e);
	else if (ft_strequ(name, "ldi") || ft_strequ(name, "lldi"))
		check_ldi(line, e);
	else if (ft_strequ(name, "ld") || ft_strequ(name, "lld"))
		check_ld(line, e);
	else if (ft_strequ(name, "add") || ft_strequ(name, "sub"))
		check_as(line);
	else if (ft_strequ(name, "sti"))
		check_sti(line, e);
	else if (ft_strequ(name, "st"))
		check_st(line, e);
	else
		print_error("Lexical error: unknown instruction", name);
}

static void			run_asm(t_env *e)
{
	int				i;
	char			**get_name;
	char			*trim;
	bool			is_asm;

	i = 0;
	is_asm = false;
	while (e->a_tmp[i])
	{
		is_asm = true;
		if (!(trim = ft_strtrim(e->a_tmp[i])))
			print_error("malloc: asm: run_asm", NULL);
		if (!ft_strequ(trim, ""))
		{
			if (!(get_name = ft_strsplit(e->a_tmp[i], ' ')))
				print_error("malloc: asm: run_asm", NULL);
			check_instr(e->a_tmp[i], get_name[0], e);
			ft_arrdel(get_name);
		}
		ft_strdel(&trim);
		i++;
	}
	if (!is_asm)
		print_error("Error: no asm code", NULL);
}

static void			run_labels(t_env *e)
{
	if (!(e->a_tmp = (char **)malloc(sizeof(char*) * ft_arrlen(e->a_file) + 1)))
		print_error("malloc: asm: run_labels", NULL);
	check_label(e);
	e->a_tmp[ft_arrlen(e->a_file)] = NULL;
}

static void			run_tags(t_env *e, size_t *i, size_t start)
{
	char			*first;
	char			*second;

	while (e->s_file[*i] && (e->s_file[*i] == ' ' || e->s_file[*i] == '\t'))
		(*i)++;
	start = *i;
	while (e->s_file[*i] && e->s_file[*i] != ' ' && e->s_file[*i] != '\t')
		(*i)++;
	first = ft_strsub(e->s_file, start, *i - start);
	check_tag(first);
	while (e->s_file[*i] && (e->s_file[*i] == ' ' || e->s_file[*i] == '\t'))
		(*i)++;
	start = *i;
	(*i)++;
	while (e->s_file[*i] && e->s_file[*i] != '"')
		(*i)++;
	(*i)++;
	second = ft_strsub(e->s_file, start, *i - start);
	check_n_c(e, second, first);
	while (e->s_file[*i] && (e->s_file[*i] == ' ' || e->s_file[*i] == '\t'))
		(*i)++;
	if (e->s_file[*i] != '\n')
		print_error("Syntax error: extraneous character(s)", NULL);
	ft_strdel(&first);
	ft_strdel(&second);
}

void				run_lexer_parser(t_env *e)
{
	size_t			i;
	size_t			start;

	i = 0;
	start = 0;
	remove_comments(e);
	e->dot_name = NULL;
	e->dot_comment = NULL;
	while (e->s_file[i])
	{
		run_tags(e, &i, start);
		i++;
	}
	if (!e->dot_name)
		print_error("Lexical error: champion name missing", NULL);
	if (!e->dot_name)
		print_error("Lexical error: comment missing", NULL);
	run_labels(e);
	run_asm(e);
	ft_arrdel(e->a_tmp);
}
