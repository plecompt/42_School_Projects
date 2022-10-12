/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:04:23 by jsivanes          #+#    #+#             */
/*   Updated: 2017/04/25 19:11:32 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		check_number(int number)
{
	t_player	*player;
	int			i;

	i = g_vm.player_count;
	while (--i >= 0)
	{
		player = &g_vm.player[i];
		if (player->forced_number == number)
			return (0);
	}
	return (1);
}

static int		get_option_2(int i, char **av, t_option *opt)
{
	if (!ft_strcmp(av[i], "-a"))
	{
		opt->aff = 1;
		return (i);
	}
	if (!ft_strcmp(av[i], "-h"))
	{
		opt->hide = 1;
		return (i);
	}
	if (!ft_strcmp(av[i], "-v"))
	{
		opt->verbose = 1;
		return (i);
	}
	error(NULL, NULL);
	return (i);
}

static int		get_option(int i, char **av, t_option *opt)
{
	if (!ft_strcmp(av[i], "-d") || !ft_strcmp(av[i], "-s"))
	{
		opt->sdump = (!ft_strcmp(av[i], "-s")) ? 1 : 0;
		(!ft_isdigit_str(av[++i])) ? error(av[i], "Only digit number allowed")
			: 0;
		opt->dump_cycle = ft_atoi(av[i]);
		(opt->dump_cycle > INT_MAX) ? error(av[i], "Upper than a INT_MAX") : 0;
		(opt->dump_cycle < 0) ? error(av[i], "Positive number only allowed")
			: 0;
		return (i);
	}
	if (!ft_strcmp(av[i], "-n"))
	{
		(!ft_isdigit_str(av[++i])) ? error(av[i], "Only digit number allowed")
			: 0;
		opt->number = ft_atoi(av[i]);
		(opt->number > INT_MAX) ? error(av[i], "Upper than a INT_MAX") : 0;
		(opt->number < 1) ? error(av[i], "Positive number only allowed") : 0;
		if (g_vm.player_count > 1)
			(!check_number(opt->number)) ? error(av[i], "Double number found")
				: 0;
		return (i);
	}
	return (get_option_2(i, av, opt));
}

void			parse_vm(int ac, char **av, t_option *opt)
{
	int		i;

	i = -1;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			i = get_option(i, av, opt);
		else
			read_player(av[i]);
	}
	if (g_vm.player_count <= 0 || g_vm.player_count > 4)
		error("Champion", "Numbers of champion allowed [1 - 4]");
	swap_position(g_vm.player);
}
