/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 13:45:50 by plecompt          #+#    #+#             */
/*   Updated: 2016/03/31 13:45:52 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_largeur(char **tab)
{
	int i;
	int j;
	int taille;
	int save;

	i = 0;
	j = 0;
	save = 0;
	taille = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			tab[i][j] != '.' ? taille++ : 0;
			j++;
		}
		if (taille == 2 && save == 2)
			taille = ft_are_you_a_square(tab);
		if (taille >= save)
			save = taille;
		j = 0;
		i++;
		taille = 0;
	}
	return (save);
}

int		ft_longueur(char **tab)
{
	int i;
	int j;
	int taille;
	int save;

	i = 0;
	j = 0;
	save = 0;
	taille = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			tab[i][j] != '.' ? taille++ : 0;
			i++;
		}
		if (taille == 2 && save == 2)
			taille = ft_are_you_a_square(tab);
		if (taille >= save)
			save = taille;
		i = 0;
		j++;
		taille = 0;
	}
	return (save);
}

int		ft_are_you_a_square(char **tab)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 0;
	ret = 3;
	while (i < 4)
	{
		while (j < 4)
		{
			if (j < 3 && i < 3)
				if (tab[i][j] != '.' && tab[i][j + 1] != '.')
					if (tab[i + 1][j] != '.' && tab[i + 1][j + 1] != '.')
						ret = 2;
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}

int		ft_sqrt(int aera)
{
	int i;

	i = 2;
	while (i * i < aera)
		i++;
	return (i);
}
