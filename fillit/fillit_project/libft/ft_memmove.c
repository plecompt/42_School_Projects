/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:47:53 by plecompt          #+#    #+#             */
/*   Updated: 2014/11/07 16:02:18 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cpy;

	cpy = (char*)malloc(sizeof(char*) * len);
	cpy = ft_strncpy(cpy, src, len);
	dst = (void*)ft_strncpy(dst, cpy, len);
	free(cpy);
	return (dst);
}
