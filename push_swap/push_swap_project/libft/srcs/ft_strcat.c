/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:13:54 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/29 16:19:31 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	if (!src)
		return (NULL);
	while (*dest)
		dest++;
	while (*(src))
		*(dest++) = *(src++);
	*dest = '\0';
	return (dest);
}
