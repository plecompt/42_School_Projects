/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:20:32 by plecompt          #+#    #+#             */
/*   Updated: 2017/02/18 17:47:54 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char *s1, char *s2)
{
	free(s2);
	free(s1);
}

char		*ft_strjoin_free(char *s1, char *s2, int free_s1_or_s2)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) *
		(ft_strlen(s2) + ft_strlen(s1) + 1))))
		return (NULL);
	if (s2 && s1 && (s2[0] == '-' && s1[0] == '0'))
	{
		s2[0] = '0';
		s1[0] = '-';
	}
	else if (s1 && s2 && (s1[0] == '-' && s2[0] == '0'))
	{
		s1[0] = '0';
		s2[0] = '-';
	}
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	if (s1 && free_s1_or_s2 == 1)
		free(s1);
	if (s2 && free_s1_or_s2 == 2)
		free(s2);
	if (free_s1_or_s2 == 3 && s1 && s2)
		ft_free(s1, s2);
	return (new);
}
