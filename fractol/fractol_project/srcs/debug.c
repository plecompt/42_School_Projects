/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:52:57 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:53:00 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		ft_reverse(char *s)
{
	char *s_end;
	char c;

	s_end = s + ft_strlen(s) - 1;
	while (s < s_end)
	{
		c = *s;
		*s++ = *s_end;
		*s_end-- = c;
	}
}

static int		ft_countchars(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	else
	{
		while (n > 0)
		{
			i++;
			n /= 10;
		}
	}
	return (i);
}

static char		*my_itoa(int n)
{
	int				i;
	unsigned int	x;
	int				sign;
	char			*buf;

	buf = ft_strnew(ft_countchars(n));
	x = n;
	if ((sign = n) < 0)
		x = -n;
	i = 0;
	if (x == 0)
		buf[i++] = '0';
	while (x > 0)
	{
		buf[i++] = x % 10 + '0';
		x /= 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	ft_reverse(buf);
	return (buf);
}

void			ft_display_debug_tree(t_env *env)
{
	char *number;

	mlx_string_put(env->mlx, env->win_tree, 10, 40, 0xFF0000, "Nb_branches =");
	mlx_string_put(env->mlx, env->win_tree, 10, 55, 0xFF0000, "Density =");
	mlx_string_put(env->mlx, env->win_tree, 110, 55, 0xFF0000, "1 px every ");
	mlx_string_put(env->mlx, env->win_tree, 10, 70, 0xFF0000, "Number of px=");
	mlx_string_put(env->mlx, env->win_tree, 10, 85, 0xFF0000, "R G B:");
	number = my_itoa(env->nbr_branch);
	mlx_string_put(env->mlx, env->win_tree, 145, 40, 0xFFFF00, number);
	free(number);
	number = ft_itoa(env->density + 1);
	mlx_string_put(env->mlx, env->win_tree, 220, 55, 0xFFFF00, number);
	free(number);
	number = ft_itoa(env->nb_of_pixel);
	mlx_string_put(env->mlx, env->win_tree, 155, 70, 0xFFFF00, number);
	free(number);
	number = ft_itoa(env->red_tree);
	mlx_string_put(env->mlx, env->win_tree, 80, 85, 0xFF0060, number);
	free(number);
	number = ft_itoa(env->green_tree);
	mlx_string_put(env->mlx, env->win_tree, 120, 85, 0x00FF00, number);
	free(number);
	number = ft_itoa(env->blue_tree);
	mlx_string_put(env->mlx, env->win_tree, 160, 85, 0x0066FF, number);
	free(number);
}
