/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:35:21 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/24 13:29:45 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *preface, char *str)
{
	if (preface != NULL)
	{
		ft_putstr(preface);
		ft_putstr(" : ");
	}
	ft_putendl_fd(str, 2);
	exit(1);
}
