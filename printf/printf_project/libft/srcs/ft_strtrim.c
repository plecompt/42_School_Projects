/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:46:46 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:46:47 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;

	begin = 0;
	if (s == NULL)
		return (NULL);
	while (s[begin] && (s[begin] == ' ' || s[begin] == '\n' \
				|| s[begin] == '\t'))
		begin++;
	if ((unsigned int)begin == ft_strlen(s))
		return (ft_strnew(1));
	end = ft_strlen((char*)s) - 1;
	while (end > begin \
			&& (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if (end >= begin)
		return (ft_strsub(s, (unsigned int)begin, (end - begin) + 1));
	else
		return (ft_strnew(1));
}
