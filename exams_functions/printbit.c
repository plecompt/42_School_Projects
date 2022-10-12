/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 13:54:44 by plecompt          #+#    #+#             */
/*   Updated: 2015/06/12 15:47:40 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcat(char *dst, const char *src)
{
	char	*begin;

	begin = dst;
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (begin);
}

char		*ft_strrev(char *str)
{
	char	tmp;
	int		len;
	int		i = -1;

	if (str)
	{
		len = ft_strlen(str);
		while (++i < len / 2)
		{
			tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
		}
	}
	return (str);
}

void		printbit(unsigned char c)
{
	int		nb;
	char	str[9];
	char	*res;
	int		i;

	nb = c;
	while (nb >= 1)					// convert
	{
		if (nb % 2 == 0)
			ft_strcat(str, "0");
		else
			ft_strcat(str, "1");
		nb = nb / 2;
	}
	i = ft_strlen(str);
	if (i > 4)						// add extra 0 (pour 8 ou 16 bits)
	{
		while (i++ < 8)				
			ft_strcat(str, "0");
	}
	else if (i < 4)
	{
		while (i++ < 4)				
			ft_strcat(str, "0");
	}
	res = ft_strrev(str);
	write(1, res, ft_strlen(str));
	write(1, "\n", 1);
}

int		main()
{
	printbit(42);
	return (0);
}
