/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:47:11 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:47:12 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*buf_save(char **line, char *save)
{
	char	*tmp;
	int		size;

	tmp = save;
	if ((tmp = ft_strchr(save, '\n')) != NULL)
	{
		*tmp = '\0';
		size = ft_strlen(save);
		*tmp = '\n';
		*line = ft_strsub(save, 0, size);
		return (save + size);
	}
	*line = ft_strdup(save);
	return (save + ft_strlen(save));
}

int		cut_buf(char **save, char *buf, char **line)
{
	if ((*save = ft_strchr(buf, '\n')) != NULL)
	{
		*save = ft_strsub(buf, (ft_strlen(buf)
								- ft_strlen(*save)), ft_strlen(*save)) + 1;
		if (*line)
			*line = ft_strjoin(*line, ft_strsub(buf, 0, ft_strlen(buf)
												- ft_strlen(*save) - 1));
		else
			*line = ft_strdup(ft_strsub(buf, 0, ft_strlen(buf)
										- ft_strlen(*save) - 1));
		return (1);
	}
	if (*line)
		*line = ft_strjoin(*line, buf);
	else
		*line = ft_strdup(buf);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static	char	*save;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	if (save)
	{
		save = buf_save(line, save);
		if (*save == '\n')
		{
			save++;
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((cut_buf(&save, buf, line)) == 1)
			return (1);
	}
	if (ret == 0)
		return (0);
	return (-1);
}
