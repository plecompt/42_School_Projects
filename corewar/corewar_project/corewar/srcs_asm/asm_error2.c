/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 10:41:50 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 16:08:06 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ldi_args(char *arg, size_t index, t_env *e)
{
	if (index == 0)
	{
		if (arg[0] == DIRECT_CHAR)
			check_dir(&arg[1], e);
		else if (arg[0] == REG_CHAR)
			check_reg(&arg[1]);
		else
			check_ind(&arg[0], e);
	}
	else if (index == 1)
		if (arg[0] == DIRECT_CHAR)
			check_dir(&arg[1], e);
		else if (arg[0] == REG_CHAR)
			check_reg(&arg[1]);
		else
			print_error("Syntax error: invalid argument", arg);
	else if (index == 2)
		check_reg(&arg[1]);
}

void			check_ldi(char *s, t_env *e)
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
		print_error("malloc: asm: check_ldi", NULL);
	check_commas(&s[i], 2);
	if (ft_arrlen(args) != 3)
		print_error("Syntax error: invalid number of argument", &s[i]);
	while (args[j])
	{
		if (!(trim = ft_strtrim(args[j])))
			print_error("malloc: asm: check_ldi", NULL);
		ldi_args(trim, j, e);
		ft_strdel(&trim);
		j++;
	}
	ft_arrdel(args);
}

static void		ld_args(char *arg, size_t index, t_env *e)
{
	if (index == 1)
		check_reg(&arg[1]);
	else if (arg[0] == DIRECT_CHAR)
		check_dir(&arg[1], e);
	else if (arg[0] == REG_CHAR)
		print_error("Syntax error: invalid argument", arg);
	else
		check_ind(&arg[0], e);
}

void			check_ld(char *s, t_env *e)
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
		print_error("malloc: asm: check_ld", NULL);
	check_commas(&s[i], 1);
	if (ft_arrlen(args) != 2)
		print_error("Syntax error: invalid number of argument", &s[i]);
	while (args[j])
	{
		if (!(trim = ft_strtrim(args[j])))
			print_error("malloc: asm: check_ld", NULL);
		ld_args(trim, j, e);
		ft_strdel(&trim);
		j++;
	}
	ft_arrdel(args);
}
