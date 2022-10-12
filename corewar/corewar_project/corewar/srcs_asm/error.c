/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:52:29 by hivian            #+#    #+#             */
/*   Updated: 2017/05/10 14:32:35 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			print_error(char *msg, char *str)
{
	char		*concat;

	if (str)
	{
		if (!(concat = (char *)malloc(sizeof(char) * (ft_strlen(msg) + \
		ft_strlen(str) + 5))))
		{
			print_error("malloc: asm: print_error", NULL);
		}
		ft_strcpy(concat, msg);
		ft_strcat(concat, ": \"");
		ft_strcat(concat, str);
		ft_strcat(concat, "\"");
		ft_putendl_fd(concat, 1);
		ft_strdel(&concat);
	}
	else
		ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}
