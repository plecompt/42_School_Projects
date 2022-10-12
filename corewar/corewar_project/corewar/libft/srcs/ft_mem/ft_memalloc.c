/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:26:53 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 14:03:34 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!size || !(ptr = (void *)malloc(size + 1)))
		return (NULL);
	if (ptr)
		ft_bzero(ptr, size + 1);
	return (ptr);
}
