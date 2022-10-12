/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 09:49:39 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/17 13:11:58 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		**ft_split(char *s)
{
	size_t	size;
	int		start;
	char	**tab;
	int		i;

	i = 0;
	size = 0;
	if (!s || !(tab = (char **)malloc(sizeof(*tab) * (ft_strlen(s) / 2 + 2))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] && (s[i] == '\t' || s[i] == ' '))
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != '\t' && s[i] != ' ')
				i++;
			if (i > start)
				tab[size++] = ft_strndup(&s[start], i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}

int			main(int ac, char **av)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(av[1]);
	if (tab)
	{
		while (tab[++i])
			printf("tab[%d] = %s\n", i, tab[i]);
	}
	return (0);
}
