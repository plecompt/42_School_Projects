/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:03:43 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 16:07:36 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			check_first(char *s, t_env *e)
{
	size_t		i;
	char		*trim;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != DIRECT_CHAR || s[i + 1] == ' ' || s[i + 1] == '\t')
		print_error("Syntax error: invalid argument", &s[i]);
	i++;
	if (!(trim = ft_strtrim(&s[i])))
		print_error("malloc: asm: check_first", NULL);
	check_dir(trim, e);
	ft_strdel(&trim);
}

void			check_aff(char *s)
{
	size_t		i;
	char		*trim;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != REG_CHAR || s[i + 1] == ' ' || s[i + 1] == '\t')
		print_error("Syntax error: invalid argument", &s[i]);
	i++;
	if (!(trim = ft_strtrim(&s[i])))
		print_error("malloc: asm: check_aff", NULL);
	check_reg(trim);
	ft_strdel(&trim);
}

static void		aox_args(char *arg, size_t index, t_env *e)
{
	if (index == 2)
		check_reg(&arg[1]);
	else if (arg[0] == DIRECT_CHAR)
		check_dir(&arg[1], e);
	else if (arg[0] == REG_CHAR)
		check_reg(&arg[1]);
	else
		check_ind(&arg[0], e);
}

void			check_aox(char *s, t_env *e)
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
		print_error("malloc: asm: check_aox", NULL);
	check_commas(&s[i], 2);
	if (ft_arrlen(args) != 3)
		print_error("Syntax error: invalid number of argument", &s[i]);
	while (args[j])
	{
		if (!(trim = ft_strtrim(args[j])))
			print_error("malloc: asm: check_aox", NULL);
		aox_args(trim, j, e);
		ft_strdel(&trim);
		j++;
	}
	ft_arrdel(args);
}
