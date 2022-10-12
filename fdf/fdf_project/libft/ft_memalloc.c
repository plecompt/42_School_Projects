/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:12:03 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/10 13:53:44 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t t)
{
	void *zone;

	zone = NULL;
	zone = malloc(t);
	if (!zone)
		return (NULL);
	ft_memset(zone, 0, t);
	return (zone);
}
