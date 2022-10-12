/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_writting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/10 14:21:41 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_write_size(t_env *e)
{
	int i;

	i = lseek(e->fd_dst, 0, SEEK_END);
	if (i < 0)
		print_error("lseek: error", NULL);
	i -= sizeof(t_header);
	e->progsize = i;
	if (lseek(e->fd_dst, 136, SEEK_SET) < 0)
		print_error("lseek: error", NULL);
	reverse_bits(&(e->progsize), sizeof(int));
	write(e->fd_dst, &e->progsize, sizeof(int));
	ft_putstr(e->file_name);
	ft_putstr(" created succesfully\n");
	ft_strdel(&e->file_name);
	e->progsize = i;
}

static int	creat_cor_file(t_env *e, char *av)
{
	int		fd;
	char	*cor_file_name;
	char	*temp;

	cor_file_name = ft_strndup(av, ft_strlen(av) - 1);
	temp = cor_file_name;
	cor_file_name = ft_strjoin(temp, "cor");
	if (!(fd = open(cor_file_name, O_RDWR | O_CREAT | O_TRUNC, 0755)))
		print_error("error creating cor file", NULL);
	e->file_name = ft_strdup(cor_file_name);
	ft_strdel(&cor_file_name);
	ft_strdel(&temp);
	return (fd);
}

void		ft_creat_header(t_env *e, char *av)
{
	t_header	*header;

	if (!(header = malloc(sizeof(t_header))))
		print_error("malloc: asm: ft_creat_header", NULL);
	ft_bzero(header, sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	*(header->prog_name) = 0;
	*(header->comment) = 0;
	ft_strcpy(header->prog_name, e->dot_name);
	ft_strcpy(header->comment, e->dot_comment);
	reverse_bits(&(header->magic), sizeof(header->magic));
	e->fd_dst = creat_cor_file(e, av);
	if (e->fd_dst)
		write(e->fd_dst, header, sizeof(*header));
	else
		print_error("Wasn't able to write in the cor file", NULL);
	free(header);
}

void		ft_write_file(t_env *e)
{
	int i;
	int x;

	lseek(e->fd_dst, 0, SEEK_END);
	i = -1;
	x = 0;
	while (++i < e->offset)
	{
		x = e->tab_instruction[i][0];
		if (e->tab_instruction[i][1] == 2)
		{
			reverse_bits(&x, sizeof(int));
			write(e->fd_dst, &x, sizeof(int));
		}
		else if (e->tab_instruction[i][1] == 1)
		{
			reverse_bits(&x, sizeof(short));
			write(e->fd_dst, &x, sizeof(short));
		}
		else
		{
			reverse_bits(&x, sizeof(char));
			write(e->fd_dst, &x, sizeof(char));
		}
	}
}
