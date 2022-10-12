/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 12:25:56 by hivian            #+#    #+#             */
/*   Updated: 2017/03/08 16:25:04 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_intdel(int **array, int nb_of_array)
{
	int		i;

	if (!array || !*array)
		return ;
	i = 0;
	while (i < nb_of_array)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
