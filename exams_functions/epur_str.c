/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 08:41:23 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/27 09:10:27 by plecompt         ###   ########.fr       */
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

char		*ft_strtrim(char *s)
{
	char	*str;
	int		len;

	while (*s == ' ' || *s == '\t')
		s++;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t')
		len--;
	str = ft_strndup(s, len);
	return (str);
}

void		epur_str(char *str)
{
	int		i;
	int		first;

	i = 0;
	first = 1;
	str = ft_strtrim(str);
	if (str)
	{
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				if (first == 1)
					write(1, &str[i], 1);
				first = 0;
			}
			else
			{
				first = 1;
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	free(str);
}

int			main(int ac, char **av)
{
	if (ac > 1)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
