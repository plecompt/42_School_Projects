/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 09:27:54 by plecompt          #+#    #+#             */
/*   Updated: 2015/03/16 11:28:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		horizontal(t_pos a, t_pos b, t_env *e, int c)
{
	float		dir;
	float		tmp;
	float		p;
	float		i;
	int			j;

	tmp = b.y - a.y;
	dir = tmp / (b.x - a.x);
	p = a.y - (dir * a.x);
	i = a.x;
	while (i < b.x)
	{
		if (tmp == 0)
			j = a.y;
		else
			j = round(dir * i + p);
		mlx_pixel_put(e->mlx, e->win, i, j, couleur(e, c));
		i += 1;
	}
}

void		vertical(t_pos a, t_pos b, t_env *e, int c)
{
	float		dir;
	float		tmp;
	float		p;
	float		i;
	int			j;

	tmp = b.x - a.x;
	dir = (b.y - a.y) / tmp;
	p = a.y - (dir * a.x);
	i = a.y;
	while (i < b.y)
	{
		if (tmp == 0)
			j = a.x;
		else
			j = round((i - p) / dir);
		mlx_pixel_put(e->mlx, e->win, j, i, couleur(e, c));
		i += 1;
	}
}

void		print(t_pos *pos, t_env *e)
{
	int			tmp;
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (y < e->nb_lines_save)
	{
		tmp = x;
		while (x + 1 <= e->len_s[y] + tmp && e->len_s[y] > 0)
		{
			horizontal(pos[x], pos[x + 1], e, e->color);
			if ((x - tmp) < e->len_s[y + 1])
			{
				e->color = rand();
				if (pos[x].y > pos[x + e->len_s[y]].y &&
						y < e->nb_lines_save - 1)
					vertical(pos[x + e->len_s[y]], pos[x], e, e->color);
				else
					vertical(pos[x], pos[x + e->len_s[y]], e, e->color);
			}
			x++;
		}
		y++;
	}
}
