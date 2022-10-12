/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:52:29 by plecompt          #+#    #+#             */
/*   Updated: 2016/10/04 11:52:31 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_exit(int error_number)
{
	if (error_number == 1)
		ft_putstr_color("Invalid argument\n", 1, 2);
	if (error_number == -1)
		ft_putstr_color("Nop Nop, c'est protégé <3\n", 1, 2);
	exit(0);
}

static void		ft_display_usage(void)
{
	ft_putstr_color("Usage : ./fractol [Julia | Mandelbrot | Tree].\n", 2, 1);
	ft_putstr_color("You can use 1 to 3 arguments.\n", 2, 1);
	ft_putstr_color("You can use two syntax for each fractal :\n", 2, 1);
	ft_putstr_color("-> Julia / julia\n-> Mandelbrot / mandelbrot\n", 2, 1);
	ft_putstr_color("-> Tree / tree\n", 2, 1);
	ft_exit(0);
}

static void		ft_check_arg(t_env *env, int arg_number)
{
	if (strcmp(env->list_arg[arg_number], "Julia") == 0)
		env->julia = 1;
	else if (strcmp(env->list_arg[arg_number], "julia") == 0)
		env->julia = 1;
	else if (strcmp(env->list_arg[arg_number], "Mandelbrot") == 0)
		env->mandelbrot = 1;
	else if (strcmp(env->list_arg[arg_number], "mandelbrot") == 0)
		env->mandelbrot = 1;
	else if (strcmp(env->list_arg[arg_number], "Tree") == 0)
		env->tree = 1;
	else if (strcmp(env->list_arg[arg_number], "tree") == 0)
		env->tree = 1;
	else if (strcmp(env->list_arg[arg_number], "-usage") == 0 ||
			ft_strcmp(env->list_arg[arg_number], "-help") == 0)
		ft_display_usage();
	else
		ft_exit(1);
}

static void		ft_list_of_arg(t_env *env, int ac, char **av)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (!(env->list_arg = (char **)malloc(sizeof(char *) * ac)))
		return ;
	while (j < ac)
	{
		if (!(env->list_arg[i] = (char *)malloc(sizeof(char) *
			(ft_strlen(av[j]) + 1))))
			return ;
		env->list_arg[i] = ft_strcpy(env->list_arg[i], av[j]);
		ft_check_arg(env, i);
		free(env->list_arg[i]);
		i++;
		j++;
	}
	free(env->list_arg);
}

int				main(int ac, char **av)
{
	t_env		env;

	if (ac > 1)
	{
		ft_init_env(&env);
		ft_list_of_arg(&env, ac, av);
		ft_init_mlx(&env);
		ft_init_env_for_julia(&env);
		ft_init_env_for_tree(&env);
		ft_init_env_for_mandelbrot(&env);
		ft_run(&env);
	}
	else
	{
		ac != 1 ? ft_putstr_color("Invalid number of parameters\n", 1, 2) : 0;
		ft_display_usage();
	}
	return (0);
}
