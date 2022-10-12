/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:20:32 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/01 14:52:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t size)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1 + size))))
		return (NULL);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strncat(new, s2, size);
	return (new);
}
