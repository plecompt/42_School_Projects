/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:26:48 by exam              #+#    #+#             */
/*   Updated: 2015/03/23 14:07:48 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr_space(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, " ", 1);
}

void		ft_putendl(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

char		*ft_strndup(char *src, int len)
{
	char	*dst;
	int		i;

	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		**ft_strsplit(char *str)
{
	char	**tab;
	int		size;
	int		i;
	int		start;

	if (!str || !(tab = (char **)malloc(sizeof(char *) * (ft_strlen(str) / 2 + 2))))
		return (NULL);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
		else
		{
			start = i;
			while (str[i] && str[i] != '\t' && str[i] != ' ')
				i++;
			if (i > start)
				tab[size++] = ft_strndup(&str[start], i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}

int			ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int			ft_strcmp_case(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (ft_tolower(*s1) - ft_tolower(*s2));
}

void		ord_alphlong(char *str)
{
	char	**tab;
	char	*tmp;
	int		i;

	i = 0;
	tab = ft_strsplit(str);
	while (tab[i + 1])
	{
		if (ft_strlen(tab[i]) > ft_strlen(tab[i + 1]))
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	i = 0;
	while (tab[i + 1])
	{
		if (ft_strlen(tab[i]) == ft_strlen(tab[i + 1]))
		{
			if (ft_strcmp_case(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				i = -1;
			}
		}
		i++;
	}
	i = 0;
	while (tab[i + 1])
	{
		if (ft_strlen(tab[i]) == ft_strlen(tab[i + 1]))
			ft_putstr_space(tab[i]);
		else
			ft_putendl(tab[i]);
		i++;
	}
	if (tab[i])
		ft_putendl(tab[i]);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ord_alphlong(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
