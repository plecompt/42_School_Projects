/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:25:08 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 16:17:11 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memalloc_2d(size_t x, size_t y)
{
	void	**tmp;
	size_t	i;

	i = 0;
	if (!(tmp = (void**)malloc(sizeof(tmp) * y + 1)))
		return (NULL);
	while (i < y)
		if (!(tmp[i++] = (void*)ft_memalloc(x)))
			return (NULL);
	tmp[y] = 0;
	return (tmp);
}
