/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:23:53 by plecompt          #+#    #+#             */
/*   Updated: 2016/11/18 11:23:54 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		convert_str_to_int(char *s, int *tab, int nb_value)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (s[++i] && j < nb_value)
	{
		if ((s[0] != ' ' && i == 0) || \
		(s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0'))
			tab[++j] = ft_atoi(&s[i]);
	}
}

int				*ft_strsplit_to_int(char const *s, t_env *e)
{
	int			*tab;
	int			nb_value;
	int			i;

	if (s == NULL)
		return (NULL);
	i = -1;
	nb_value = 0;
	while (s[++i])
	{
		if ((s[0] != ' ' && i == 0) || \
			(s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0'))
			nb_value++;
	}
	e->nb_square += nb_value;
	e->nb_line += 1;
	tab = (int *)malloc(sizeof(int) * nb_value);
	if (tab)
		convert_str_to_int((char *)s, tab, nb_value);
	else
		return (NULL);
	return (tab);
}

static void		get_arg(char *arg, int *fd)
{
	get_next_line(0, &arg);
	if (ft_strequ(arg, "map0"))
	{
		*fd = open("./maps/map0", O_RDONLY);
		free(arg);
		*fd == -1 ? ft_putstr_color("Can't open the map\n", 1, 2) : 0;
		*fd == -1 ? exit(0) : 0;
	}
	else if (ft_strequ(arg, "map1"))
	{
		*fd = open("./maps/map1", O_RDONLY);
		free(arg);
		*fd == -1 ? ft_putstr_color("Can't open the map\n", 1, 2) : 0;
		*fd == -1 ? exit(0) : 0;
	}
	else if (ft_strequ(arg, "exit"))
		exit(EXIT_SUCCESS);
	else
	{
		ft_putstr_color("Invalid map\n", 1, 2);
		ft_putstr_color("map0 or map1 | exit >> ", 2, 1);
		get_arg(arg, fd);
		free(arg);
	}
}

void			ft_init_map(t_env *e)
{
	char	*buff;
	int		i;
	int		fd;
	char	*arg;

	arg = NULL;
	fd = 0;
	i = 0;
	buff = NULL;
	if (!(e->world_map = (int **)malloc(sizeof(int *) * MAP_HEIGHT)))
		return ;
	ft_putstr_color("Please choose a map or exit\n", 2, 1);
	ft_putstr_color("map0 or map1 | exit >> ", 2, 1);
	get_arg(arg, &fd);
	while (get_next_line(fd, &buff) == 1)
	{
		e->world_map[i] = ft_strsplit_to_int(buff, e);
		free(buff);
		i++;
	}
	free(buff);
	close(fd);
}
