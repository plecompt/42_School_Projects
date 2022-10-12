/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by hivian            #+#    #+#             */
/*   Updated: 2017/04/14 12:14:56 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*strchr_last(const char *s, int c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(s);
	while (s[len - 1] > 0 && s[len - 1] != c)
		len--;
	if (s[len - 1] == c)
		return ((char*)(s) + len - 1);
	return (NULL);
}

static void		check_file_ext(char *arg)
{
	char		*ext;

	if ((ext = strchr_last(arg, '.')) == NULL || !ft_strequ(ext, ".s"))
		print_error("Error: extension file", NULL);
}

static void		ft_free(t_env *e)
{
	close(e->fd_src);
	close(e->fd_dst);
	ft_arrdel(e->a_file);
	ft_strdel(&e->s_file);
	ft_strdel(&e->dot_name);
	ft_strdel(&e->dot_comment);
	clear_list(e->labels);
	if (e->nb_of_label || e->nb_of_label_call)
	{
		e->label[e->nb_of_label] = NULL;
		e->label_sneak[e->nb_of_label_call] = NULL;
		ft_arrdel(e->label);
		ft_arrdel(e->label_sneak);
	}
	ft_intdel(e->tab_instruction, e->nb_instruction);
	ft_intdel(e->label_offset_sneak, e->nb_of_label + e->nb_of_label_call);
	free(e->label_offset);
	free(e->off_limit);
	free(e);
}

int				main(int ac, char **av)
{
	t_env		*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	e->verbose = 0;
	if (ac == 3 && ft_strcmp(av[1], "-v") == 0)
		e->verbose = 1;
	else if (ac != 2)
		print_error("Usage: ./asm [-v] <file.s>", NULL);
	check_file_ext(av[1 + e->verbose]);
	open_file(av[1 + e->verbose], e);
	save_file(e);
	run_lexer_parser(e);
	run_encoder(e);
	ft_creat_header(e, av[1 + e->verbose]);
	ft_write_file(e);
	ft_write_size(e);
	if (e->verbose)
	{
		ft_display_informations(e);
		ft_display_offset(e);
		ft_display_label_list(e);
	}
	ft_free(e);
	return (0);
}
