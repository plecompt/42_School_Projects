/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:17:04 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 16:08:21 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		as_args(char *arg)
{
	if (arg[0] == REG_CHAR)
		check_reg(&arg[1]);
	else
		print_error("Syntax error: invalid argument", arg);
}

void			check_as(char *s)
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
		print_error("malloc: asm: check_as", NULL);
	check_commas(&s[i], 2);
	if (ft_arrlen(args) != 3)
		print_error("Syntax error: invalid number of argument", &s[i]);
	while (args[j])
	{
		if (!(trim = ft_strtrim(args[j])))
			print_error("malloc: asm: check_as", NULL);
		as_args(trim);
		ft_strdel(&trim);
		j++;
	}
	ft_arrdel(args);
}
