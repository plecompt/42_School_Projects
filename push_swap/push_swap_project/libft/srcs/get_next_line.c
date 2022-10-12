/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:19:58 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/20 10:53:22 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*my_realloc(void *ptr, size_t size)
{
	void	*dup;

	if (!(dup = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(dup, ptr, size);
	ft_memdel(&ptr);
	return (dup);
}

static void		my_copy(char **line, char *buff, int *i, int fd)
{
	int ret;
	int j;

	j = 0;
	while (buff[*i] != '\n' && buff[*i])
	{
		(*line)[j++] = buff[(*i)++];
		if (buff[*i] == '\0' && (ret = read(fd, buff, BUFF_SIZE)))
		{
			*line = my_realloc(*line, ft_strlen(*line) + (BUFF_SIZE + 1));
			buff[ret] = '\0';
			*i = 0;
		}
	}
	(*line)[j] = '\0';
}

int				get_next_line(int const fd, char **line)
{
	static char buff[BUFF_SIZE + 1];
	static int	ret = 0;
	static int	i = 0;

	if (!(*line = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	ft_bzero(*line, ft_strlen(*line));
	if (ret == 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) <= 0)
			return (ret);
		buff[ret] = '\0';
	}
	my_copy(line, buff, &i, fd);
	if (buff[i] == '\n' && buff[i + 1] != '\0')
		i++;
	else
	{
		ret = 0;
		i = 0;
	}
	return (1);
}
