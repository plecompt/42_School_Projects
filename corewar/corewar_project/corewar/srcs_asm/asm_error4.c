/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:48:04 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 16:08:48 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		st_args(char *arg, size_t index, t_env *e)
{
	if (index == 0)
		if (arg[0] == REG_CHAR)
			check_reg(&arg[1]);
		else
			print_error("Syntax error: invalid argument", arg);
	else if (index == 1)
	{
		if (arg[0] == REG_CHAR)
			check_reg(&arg[1]);
		else
			check_ind(&arg[0], e);
	}
}

void			check_st(char *s, t_env *e)
{
	size_t		i;
	size_t		j;
	char		**args;
	char		*trim;

	i = 0;
	j = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (!(args = ft_strsplit(&s[i], ',')))
		print_error("malloc: asm: check_st", NULL);
	check_commas(&s[i], 1);
	if (ft_arrlen(args) != 2)
		print_error("Syntax error: invalid number of argument", &s[i]);
	while (args[j])
	{
		if (!(trim = ft_strtrim(args[j])))
			print_error("malloc: asm: check_st", NULL);
		st_args(trim, j, e);
		ft_strdel(&trim);
		j++;
	}
	ft_arrdel(args);
}

static void		sti_args(char *arg, size_t index, t_env *e)
{
	if (index == 0)
		if (arg[0] == REG_CHAR)
			check_reg(&arg[1]);
		else
			print_error("Syntax error: invalid argument", arg);
	else if (index == 1)
	{
		if (arg[0] == DIRECT_CHAR)
			check_dir(&arg[1], e);
		else if (arg[0] == REG_CHAR)
			check_reg(&arg[1]);
		else
			check_ind(&arg[0], e);
	}
	else if (index == 2)
	{
		if (arg[0] == DIRECT_CHAR)
			check_dir(&arg[1], e);
		else if (arg[0] == REG_CHAR)
			check_reg(&arg[1]);
		else
			print_error("Syntax error: invalid argument", arg);
	}
}

void			check_sti(char *s, t_env *e)
{
	size_t		i;
	size_t		j;
	char		**args;
	char		*trim;

	i = 0;
	j = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (!(args = ft_strsplit(&s[i], ',')))
		print_error("malloc: asm: check_sti", NULL);
	check_commas(&s[i], 2);
	if (ft_arrlen(args) != 3)
		print_error("Syntax error: invalid number of argument", &s[i]);
	while (args[j])
	{
		if (!(trim = ft_strtrim(args[j])))
			print_error("malloc: asm: check_sti", NULL);
		sti_args(trim, j, e);
		ft_strdel(&trim);
		j++;
	}
	ft_arrdel(args);
}
