/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:52:57 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:53:00 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		my_pixel_put_to_image(t_env *env, int x, int y)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		i;

	env->nb_of_pixel++;
	data = mlx_get_data_addr(env->img_tree, &bpp, &sizeline, &endian);
	i = x * 4 + y * sizeline;
	if (env->nb_branch_draw == 1)
	{
		data[i + 2] = mlx_get_color_value(env->mlx, env->red_tree);
		data[i + 1] = mlx_get_color_value(env->mlx, env->green_tree);
		data[i] = mlx_get_color_value(env->mlx, env->blue_tree);
	}
	else
	{
		data[i + 2] = 96;
		data[i + 1] = 0x3C;
		data[i] = 0;
	}
}

static void		ft_draw_segment(t_env *env, int x0, int y0, int *tab2)
{
	env->draw = 0;
	env->dx = abs(tab2[0] - x0);
	env->sx = x0 < tab2[0] ? 1 : -1;
	env->dy = abs(tab2[1] - y0);
	env->sy = y0 < tab2[1] ? 1 : -1;
	env->err = (env->dx > env->dy ? env->dx : -env->dy) / 2;
	while (42)
	{
		if ((x0 >= 0 && x0 <= TREE_WIDTH - 1) &&
			(y0 >= 0 && y0 <= TREE_HEIGHT - 1) && env->draw == env->density)
			my_pixel_put_to_image(env, x0, y0);
		env->draw++;
		env->draw = env->draw == env->density + 1 ? 0 : env->draw;
		if (x0 == tab2[0] && y0 == tab2[1])
			break ;
		env->e2 = env->err;
		if (env->e2 > -env->dx)
			env->e2 > -env->dx ? env->err -= env->dy : 0;
		env->e2 > -env->dx ? x0 += env->sx : 0;
		env->e2 < env->dy ? env->err += env->dx : 0;
		env->e2 < env->dy ? y0 += env->sy : 0;
	}
}

void			ft_calc_tree(t_env *env, int *tab, double angle, int nb_brch)
{
	int tab_1[2];

	if (nb_brch == 1)
		env->nb_branch_draw = 1;
	else
		env->nb_branch_draw = 0;
	if (nb_brch == 0)
		return ;
	tab_1[0] = tab[0] + (int)(cos(angle) * 3) * nb_brch * env->size_grow;
	tab_1[1] = tab[1] - ((int)(sin(angle) * 5) * nb_brch) * env->size_grow;
	ft_draw_segment(env, tab[0], tab[1], tab_1);
	ft_calc_tree(env, tab_1, angle + env->value, nb_brch - 1);
	ft_calc_tree(env, tab_1, angle - env->value, nb_brch - 1);
}
