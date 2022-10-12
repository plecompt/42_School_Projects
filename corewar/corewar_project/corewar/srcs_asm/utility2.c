/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:13 by plecompt          #+#    #+#             */
/*   Updated: 2017/05/10 15:52:56 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		malloc_epured(char *str)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != '\0')
		{
			cpt++;
			while (str[i] == ' ' || str[i] == '\t')
				i++;
		}
		if (str[i] != ' ' && str[i] != '\t')
			cpt++;
		i++;
	}
	return (cpt);
}

char	*epur_str(char *s)
{
	int		i;
	int		x;
	char	*new;

	i = 0;
	x = 0;
	if (!(new = malloc((malloc_epured(s) + 1) * sizeof(char))))
		print_error("malloc: asm: epur_str", NULL);
	while (s[i] == ' ')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == ' ' || s[i] == '\t') && s[i + 1] != '\0')
		{
			while (s[i] == ' ' || s[i] == '\t')
				i++;
			if (s[i] != '\0')
				new[x++] = ' ';
		}
		if (s[i] != ' ' && s[i] != '\t')
			new[x++] = s[i];
		i++;
	}
	new[x] = '\0';
	return (new);
}

void	ft_epur_from_comma(t_env *e, char c, int index)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (e->a_file[index][j])
	{
		if (e->a_file[index][j] != c)
		{
			e->a_file[index][i] = e->a_file[index][j];
			i++;
			j++;
		}
		else
		{
			e->a_file[index][i] = ' ';
			i++;
			j++;
		}
	}
	e->a_file[index][i] = '\0';
}

void	*reverse_bits(void *buff, int size)
{
	static int	i = 0;
	char		tmp;
	int			n;
	char		*p;

	p = buff;
	n = size / 2;
	while (n > 0)
	{
		tmp = (*(unsigned char*)(p + n - 1));
		(*(unsigned char*)(p + n - 1)) =
			(*(unsigned char*)(p + size - n));
		(*(unsigned char*)(p + size - n)) = tmp;
		n--;
	}
	i++;
	return (buff);
}
