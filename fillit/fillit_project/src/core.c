/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:18:10 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 16:44:42 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_resolve(t_coord *c, int piece)
{
	if (piece >= c->nb_trio)
	{
		ft_display_plateau(c);
		exit(0);
	}
	else
	{
		while (ft_move_to_next_one(c, piece + 1) == 1)
		{
			ft_resolve(c, piece + 1);
			ft_clear_that_one(c, piece + 1);
		}
		ft_reset_xy_for_piece(c, piece + 1);
		if (piece == 0)
		{
			c->size++;
			ft_resolve(c, piece);
		}
	}
}

void		ft_algo(t_coord *c)
{
	reset(c);
	c->size = ft_sqrt(c->nb_trio * 4);
	ft_creat_plateau(c);
	ft_malloc_coord(c);
	ft_resolve(c, 0);
}

void		ft_starter(int fd, t_coord *c, char *argv)
{
	char		*buffer;
	int			size_file;

	if (!(buffer = (char *)malloc(600)))
		return ;
	size_file = read(fd, buffer, 600);
	close(fd);
	fd = open(argv, O_RDONLY);
	if (!(c->tab = (char*)malloc(sizeof(char) * size_file + 1)))
		return ;
	read(fd, c->tab, size_file + 1);
	c->tab[ft_strlen(c->tab)] = '\0';
	c->tab[0] == '#' || c->tab[0] == '.' ? 0 : ft_exit();
	size_file <= 545 && size_file >= 20 ? 0 : ft_exit();
	c->tab[size_file - 1] == '\n' && c->tab[size_file - 2] !=
		'\n' ? ft_malloc_tab2d(c) : ft_exit();
}

int			main(int argc, char **argv)
{
	int			fd;
	t_coord		*c;

	c = ft_init_struct();
	fd = -1;
	argc != 2 ? ft_putstr("usage: ./fillit test_file\n") : 0;
	argc != 2 ? exit(0) : 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		ft_starter(fd, c, argv[1]);
		ft_malloc_tab3d_check(c);
		ft_check_tab(c);
		ft_transform(c);
		ft_malloc_tab3d_suprem(c);
		ft_malloc_dimension(c);
		ft_parse(c);
		ft_i_want_to_break_free(c);
		ft_algo(c);
	}
	else
		ft_exit();
	return (0);
}
