/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:48 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/23 12:19:05 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			**init_tab_func(void)
{
	static char	*op[12];

	op[0] = "sa";
	op[1] = "sb";
	op[2] = "ss";
	op[3] = "pa";
	op[4] = "pb";
	op[5] = "ra";
	op[6] = "rb";
	op[7] = "rr";
	op[8] = "rra";
	op[9] = "rrb";
	op[10] = "rrr";
	op[11] = "";
	return (op);
}

static void		resolve(t_push *list, char **op, void (*func[])(t_push *))
{
	char	*line;
	int		i;

	line = NULL;
	while (get_next_line(0, &line))
	{
		i = 0;
		while (i < 12)
		{
			if (ft_strlen(line) > 0)
			{
				if (ft_strcmp(line, op[i]) == 0)
				{
					(*func[i])(list);
					break ;
				}
			}
			i++;
			if (i == 12)
				error();
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

static void		check_stdout(t_push *list)
{
	void	(*func[11])(t_push*);
	char	**op;

	func[0] = swap_a;
	func[1] = swap_b;
	func[2] = swap_ss;
	func[3] = push_a;
	func[4] = push_b;
	func[5] = rotate_a;
	func[6] = rotate_b;
	func[7] = rotate_rr;
	func[8] = rev_rotate_a;
	func[9] = rev_rotate_b;
	func[10] = rev_rotate_rr;
	op = init_tab_func();
	resolve(list, op, func);
}

int				main(int argc, char **argv)
{
	t_data	data;
	t_push	*list;

	if (!(list = (t_push *)malloc(sizeof(t_push))))
		return (0);
	data_init(&data, list);
	list->data = &data;
	parser(argc, argv, list);
	check_stdout(list);
	if (ft_list_is_sort(list->p_a, 1))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
