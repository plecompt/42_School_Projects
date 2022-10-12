/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 14:22:21 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/25 14:20:34 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strndup(char *src, int len)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int			ft_strnstr(char *s1, char *s2, int len)
{
	int		i;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			s1++;
			continue ;
		}
		i = 0;
		while (s1[i] == s2[i] && i < len)
			i++;
		if (!s2[i] || i == len)
			return (1);
		s1++;
	}
	return (0);
}

int			ft_strstr_arr(int ac, char **av, char *str, int len)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!(ft_strnstr(av[i], str, len)))
			return (0);
		i++;
	}
	return (1);
}

void		str_maxlenoc(int ac, char **av)
{
	char	*str;
	char	*max;
	int		i;

	i = 0;
	str = av[1];
	max = NULL;
	while (*str)
	{
		i = 0;
		while (str[i])
		{
			if ((!max || (i + 1 > ft_strlen(max))) && ft_strstr_arr(ac, av, str, i + 1))
				max = ft_strndup(str, i + 1);
			i++;
		}
		str++;
	}
	if (max)
	{
		write(1, max, ft_strlen(max));
		free(max);
	}
}

int			main(int ac, char **av)
{
	if (ac > 1)
		str_maxlenoc(ac, av);
	write(1, "\n", 1);
	return (0);
}
