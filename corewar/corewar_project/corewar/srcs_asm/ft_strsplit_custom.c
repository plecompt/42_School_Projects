/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_custom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/10 15:33:08 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_strnewtrim(int *start, int *i, char c, const char *s)
{
	while (s[(*i)] && (s[(*i)] == c))
		(*i)++;
	(*start) = (*i);
}

static int		ft_split_part2(int *i, const char **s, char ***tab, int *d)
{
	if ((*s)[(*i)] == ':' && (*s)[(*i) - 1] != '%' && (*s)[(*i) - 1] != ' ' &&
			(*s)[(*i) + 1] != ' ')
	{
		if (!((*tab)[(*d)++] = ft_strsub((*s), 0, (*i) + 1)))
			print_error("malloc: asm: ft_split_part2", NULL);
		return (1);
	}
	return (0);
}

char			**ft_stronesplit(char const *s, char c)
{
	int		i;
	int		d;
	int		start;
	int		end;
	char	**tab;

	i = 0;
	d = 0;
	if (!s || !(tab = (char **)malloc(sizeof(*tab) * (ft_strlen(s) / 2 + 2))))
		print_error("malloc: asm: ft_stronesplit", NULL);
	while (s[i] != '\0')
	{
		ft_strnewtrim(&start, &i, c, s);
		while (s[i] && s[i] != ' ')
		{
			start = ft_split_part2(&i, &s, &tab, &d) == 1 ? i + 1 : start;
			i++;
		}
		end = i;
		if (end > start)
			if (!(tab[d++] = ft_strsub(s, start, (end - start))))
				print_error("malloc: asm: ft_stronesplit", NULL);
	}
	tab[d] = NULL;
	return (tab);
}
