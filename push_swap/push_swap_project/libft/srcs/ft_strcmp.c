/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:48:57 by plecompt          #+#    #+#             */
/*   Updated: 2017/01/19 11:42:56 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t len;
	size_t len_2;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + 1;
	len_2 = ft_strlen(s2) + 1;
	if (len > len_2)
		len = len_2;
	return (ft_memcmp(s1, s2, len));
}
