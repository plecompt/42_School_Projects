/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:35:11 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 15:24:25 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	d;
	int		start;
	int		end;
	char	**tab;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_strlen(s) / 2 + 2))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] && (s[i] == c || s[i] == '\t'))
			i++;
		start = i;
		while (s[i] && s[i] != c && s[i] != '\t')
			i++;
		end = i;
		if (end > start)
			tab[d++] = ft_strsub(s, start, (end - start));
	}
	tab[d] = NULL;
	return (tab);
}
