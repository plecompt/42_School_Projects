/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:46:30 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:46:31 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		count_words(char const *s, char sep)
{
	size_t	i;
	int		out;

	i = 0;
	out = 1;
	while (*s)
	{
		if (*s == sep && !out)
			out = 1;
		else if (*s != sep && out)
		{
			i++;
			out = 0;
		}
		s++;
	}
	return (i);
}

static int		word_len(char const *s, char sep, size_t start)
{
	int	cpt;

	cpt = 0;
	while (s[start] != '\0' && s[start] != sep)
	{
		cpt++;
		start++;
	}
	return (cpt);
}

static void		tab_push(char **tab, char const *s, char sep)
{
	size_t	len;
	size_t	i;
	int		cpt;

	cpt = 0;
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != sep)
		{
			len = word_len(s, sep, i);
			tab[cpt++] = ft_strdup(ft_strsub(s, i, len));
		}
		i += (s[i] != sep) ? len : 1;
	}
	tab[cpt] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = (char **)malloc(sizeof(char*) * (words + 1));
	if (!tab)
		return (NULL);
	tab_push(tab, s, c);
	return (tab);
}
