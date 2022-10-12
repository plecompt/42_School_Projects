/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:39:04 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:39:05 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pm;
	char	*res;
	size_t	i;

	pm = (void *)malloc(size);
	res = (char *)pm;
	i = 0;
	if (pm)
	{
		while (i < size)
		{
			res[i] = 0;
			i++;
		}
	}
	else
		return (NULL);
	return (pm);
}
