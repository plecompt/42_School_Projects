/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 13:54:58 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/17 12:06:08 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void		find_island(char *buff, int i, int size_line, int nb)
{
	if (buff[i] == 'X')
	{
		buff[i] = nb + '0';
		find_island(buff, i + 1, size_line, nb);
		find_island(buff, i - 1, size_line, nb);
		find_island(buff, i + size_line, size_line, nb);
		find_island(buff, i - size_line, size_line, nb);
	}
}

void		draw_map(int fd, int nb_line, int size_line)
{
	char	buff[nb_line * size_line + nb_line];
	int		buff_size;
	int		nb;
	int		i;

	i = -1;
	nb = 0;
	buff_size = nb_line * size_line + nb_line;
	read(fd, buff, buff_size);
	while (++i < buff_size)
	{
		if (buff[i] == 'X')
		{
			find_island(buff, i, size_line + 1, nb);
			nb++;
		}
	}
	write(1, buff, buff_size);
}

int			read_map(int fd, int *nb_line, int *size_line)
{
	char	buff[1000000];
	int		ret;
	int		verif;
	int		size;
	int		i;

	size = -1;
	verif = 0;
	while (++size < 1000000)
		buff[size] = '\0';
	size = 0;
	while ((ret = read(fd, buff, 999999)) > 0)
	{
		i = -1;
		if ((buff[ret] == '\0' && buff[ret - 1] != '\n'))
				return (0);
		while (++i < ret)
		{
			if (buff[i] != '\n' && buff[i] != 'X' && buff[i] != '.')
				return (0);
			if (buff[i] == '\n')
			{
				if (size > 1024)
					return (0);
				if (!verif)
					verif = size;
				if (verif != size)
					return (0);
				(*nb_line)++;
				size = 0;
			}
			else
				size++;
		}
	}
	*size_line = verif;
	return (1);
}

int			count_island(char *map)
{
	int		fd1;
	int		fd2;
	int		nb_line;
	int		size_line;

	nb_line = 0;
	size_line = 0;
	fd1 = open(map, O_RDONLY);
	if (!read_map(fd1, &nb_line, &size_line))
		return (0);
	fd2 = open(map, O_RDONLY);
	draw_map(fd2, nb_line, size_line);
	close(fd1);
	close(fd2);
	return (1);
}

int			main(int ac, char **av)
{
	char	buff[1024];
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		write(1, "\n", 1);
	else if (read(fd, buff, 1024) == 0)
		write(1, "\n", 1);
	else if (ac == 2)
	{
		if (!count_island(av[1]))
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	close(fd);
	return (0);
}
