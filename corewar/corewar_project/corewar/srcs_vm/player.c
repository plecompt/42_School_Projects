/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:37:16 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 16:58:11 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player		*find_player(int id)
{
	t_player	*player;
	int			i;

	i = 0;
	while (i < g_vm.player_count)
	{
		player = &g_vm.player[i];
		if (player->number == id)
			return (player);
		i++;
	}
	return (NULL);
}

static int		get_header(int fd, t_player *player)
{
	ssize_t		readed;
	t_header	header;
	int			magic;

	magic = 0;
	lseek(fd, 0, SEEK_SET);
	readed = read(fd, (char*)&header, sizeof(t_header));
	if (readed < 0)
		return (0);
	rev_cpy((char*)&magic, (char*)&header.magic, sizeof(int));
	if (magic != COREWAR_EXEC_MAGIC)
		return (0);
	if (!(player->name = ft_strdup(header.prog_name)))
		error("Memory", "get_header");
	if (!(player->comment = ft_strdup(header.comment)))
		error("Memory", "get_header");
	rev_cpy((char*)&player->prog_size, (char*)&header.prog_size, sizeof(int));
	return (1);
}

static void		read_player_file(char *file, t_player *player)
{
	int		fd;
	off_t	offset;

	if ((fd = open(file, O_RDONLY)) < 0)
		error(file, "Can't open the file.");
	offset = lseek(fd, 0, SEEK_END);
	(offset < (off_t)sizeof(t_header)) ? error(file, "Champion too small.") : 0;
	if (offset - (off_t)sizeof(t_header) > CHAMP_MAX_SIZE)
		error(file, "Champion bigger than allowed size.");
	if (!get_header(fd, player))
		error(file, "Wrong size of header.");
	if (!(player->bytecode = (char*)ft_memalloc(player->prog_size)))
		error("Memory", "read_player_file");
	if (offset != (off_t)(sizeof(t_header) + player->prog_size))
		error(file, "Prog_size of header is different than real prog_size");
	offset = lseek(fd, 0, SEEK_CUR);
	if (read(fd, player->bytecode, player->prog_size) < 0)
		error(file, "Prog_size of header is different than real prog_size");
	close(fd);
}

void			read_player(char *file)
{
	int			count;
	t_player	*this_player;

	count = ft_strlen(file);
	if (file[count - 1] != 'r' && file[count - 2] != 'o' && file[count - 3] \
			!= 'c' && file[count - 4] != '.')
		error(file, "Wrong type of file. only [name.cor]");
	count = ++g_vm.player_count;
	g_vm.player = (t_player*)realloc(g_vm.player, sizeof(t_player) * count);
	this_player = &g_vm.player[count - 1];
	ft_bzero(this_player, sizeof(t_player));
	this_player->number = (g_vm.option.number) ? g_vm.option.number :
												g_vm.player_count;
	this_player->forced_number = g_vm.option.number;
	g_vm.option.number = 0;
	read_player_file(file, this_player);
}
