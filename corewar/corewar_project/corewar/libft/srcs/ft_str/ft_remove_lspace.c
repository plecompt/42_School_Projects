/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_lspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:31:02 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 15:50:32 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*malloc_by_len(char *str, int *strlen)
{
	char		*res;
	int			len;
	int			i;

	len = 0;
	res = NULL;
	if (str && str[0])
	{
		*strlen = ft_strlen(str);
		i = -1;
		while (++i < *strlen)
		{
			if (str[i] == '\t' || str[i] == ' ')
			{
				len++;
				while (str[i] && (str[i] == '\t' || str[i] == ' '))
					i++;
				i--;
			}
			else
				len++;
		}
		res = ft_strnew(len);
	}
	return (res);
}

char			*ft_remove_lspace(char *str)
{
	char		*res;
	int			len;
	int			i;
	int			j;

	res = ft_strtrim(str);
	free(str);
	str = res;
	if ((res = malloc_by_len(str, &len)) == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] == '\t' || str[i] == ' ')
		{
			res[j++] = ' ';
			while (str[i] && (str[i] == '\t' || str[i] == ' '))
				i++;
		}
		else
			res[j++] = str[i++];
	}
	free(str);
	return (res);
}
