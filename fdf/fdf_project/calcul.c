/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 09:32:30 by plecompt          #+#    #+#             */
/*   Updated: 2015/02/11 15:20:48 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_read(t_env *e)
{
	t_pos	*pos;
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	pos = (t_pos *)malloc(sizeof(t_pos) * e->nb);
	while (e->tab_int_save[y] != NULL)
	{
		x = 0;
		while (x < e->len_s[y])
		{
			pos[i].x = (e->zoom_x * x - e->zoom_x * y) + (WIDTH / e->move_hori);
			pos[i].y = (e->zoom_y * x + e->zoom_y * y) -
				(e->height * e->tab_int_save[y][x]) + (LENGTH / e->move_verti);
			x++;
			i++;
		}
		y++;
	}
	print(pos, e);
}

int			*height_len(char ***tab, int nb_lines)
{
	int		*len;
	int		i;
	int		block;
	int		tmp;

	i = 0;
	len = (int *)malloc(sizeof(int) * (nb_lines + 1));
	while (tab[i])
	{
		block = 0;
		tmp = 0;
		while (tab[i][block])
		{
			tmp++;
			block++;
		}
		len[i] = tmp;
		i++;
	}
	i = 0;
	return (len);
}

void		convert_to_int(char ***tab, int nb_lines, t_env *e)
{
	int		i;
	int		block;
	int		tmp;

	i = 0;
	e->tab_int_save = (int **)malloc(sizeof(int *) * (nb_lines + 1));
	e->len_s = height_len(tab, nb_lines);
	while (tab[i])
	{
		block = 0;
		tmp = 0;
		e->tab_int_save[i] = (int *)malloc(sizeof(int) * e->len_s[i]);
		while (tab[i][block])
		{
			e->tab_int_save[i][block] = ft_getnbr(tab[i][block]);
			block++;
			tmp++;
		}
		e->nb = e->nb + tmp;
		e->len_s[i++] = tmp;
	}
	ft_read(e);
}

void		print_fdf(t_env e)
{
	char	*line;
	char	**tab;
	int		fd;
	int		block;

	e.nb_lines_save = 0;
	block = 0;
	fd = open(e.av[1], O_RDONLY);
	if (get_next_line(fd, &line) == 0)
		return ;
	while (get_next_line(fd, &line))
		e.nb_lines_save++;
	e.nb_lines_save++;
	close(fd);
	fd = open(e.av[1], O_RDONLY);
	tab = (char **)malloc(sizeof(char *) * e.nb_lines_save + 1);
	while (get_next_line(fd, &line))
		tab[block++] = ft_strdup(line);
	tab[e.nb_lines_save] = NULL;
	ft_final_tab(tab, e.nb_lines_save, &e);
}

void		ft_final_tab(char **tab, int nb_lines, t_env *e)
{
	char	***final_tab;
	int		height;

	height = 0;
	final_tab = (char ***)malloc(sizeof(char **) * nb_lines + 1);
	if (final_tab == NULL)
		return ;
	while (tab[height])
	{
		final_tab[height] = ft_strsplit(tab[height], ' ');
		height++;
	}
	final_tab[height] = NULL;
	convert_to_int(final_tab, nb_lines, e);
}
