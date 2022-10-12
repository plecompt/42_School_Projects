/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:10:14 by hivian            #+#    #+#             */
/*   Updated: 2017/04/25 12:19:27 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			check_commas(char *s, size_t max)
{
	size_t		nb_commas;
	size_t		i;

	i = 0;
	nb_commas = 0;
	while (s[i])
	{
		if (s[i] == ',')
			nb_commas++;
		if (nb_commas > max)
			print_error("Syntax error: invalid number of argument", s);
		i++;
	}
}

void			check_dir(char *s, t_env *e)
{
	long int	tmp;

	if (*s == ' ' || *s == '\t')
		print_error("Syntax error: invalid argument", s);
	if (*s == LABEL_CHAR)
	{
		s++;
		if (!label_exist(s, e))
			print_error("Lexical error: invalid label", s);
	}
	else if (!ft_isnumber(s))
		print_error("Lexical error: invalid direct number", s);
	else
		tmp = ft_latoi(s);
}

void			check_reg(char *s)
{
	long int	tmp;

	tmp = ft_latoi(s);
	if (*s == '-')
		print_error("Lexical error: invalid reg. number", s);
	if (*s == ' ' || *s == '\t')
		print_error("Syntax error: invalid argument", s);
	if (!ft_isnumber(s))
		print_error("Lexical error: invalid register", s);
	if (ft_strlen(s) > 10)
		print_error("Syntax error: number too long", s);
	if (tmp < 1 || tmp > 16)
		print_error("Lexical error: register must be between 1 and 16", s);
}

void			check_ind(char *s, t_env *e)
{
	long int	tmp;

	if (*s == LABEL_CHAR)
	{
		s++;
		if (!label_exist(s, e))
			print_error("Lexical error: invalid label", s);
	}
	else if (!ft_isnumber(s))
		print_error("Syntax error: invalid indirect number", s);
	else
		tmp = ft_latoi(s);
}
