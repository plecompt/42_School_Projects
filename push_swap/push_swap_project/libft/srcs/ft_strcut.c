/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:45:52 by plecompt          #+#    #+#             */
/*   Updated: 2016/12/29 16:19:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_c(char *str, char c)
{
	int	nb;
	int	j;
	int start;

	nb = 0;
	j = 2;
	start = 0;
	while (str[++j])
	{
		if (str[j] == c && start != 1)
			nb++;
		if (str[j] != c)
			start = 1;
	}
	return (nb);
}

char		*ft_strcut(char *str, char c)
{
	int		i;
	int		j;
	int		start;
	char	*new;

	if (!str)
		return (NULL);
	if (!(new = malloc(sizeof(char) * ft_strlen_c(str, c))))
		return (NULL);
	j = 1;
	i = 2;
	start = 0;
	new[0] = str[0];
	new[1] = str[1];
	while (str[++j])
	{
		if (str[j] != c || start == 1)
		{
			new[i++] = str[j];
			start = 1;
		}
	}
	free(str);
	return (new);
}
