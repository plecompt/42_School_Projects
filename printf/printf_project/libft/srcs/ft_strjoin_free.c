/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:20:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:06:44 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dst;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if ((dst = ft_strnew(len + 1)) == 0)
		return (NULL);
	else
	{
		ft_strcpy(dst, s1);
		ft_strcat(dst, s2);
	}
	free(s1);
	free(s2);
	return (dst);
}
