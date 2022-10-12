/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:45:19 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 12:45:20 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_str_capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0) || (!ft_isalnum((int)str[i]) &&
						(str[i + !!i] <= 'a' && str[i + !!i] <= 'z')))
			str[i + !!i] -= 32;
		i++;
	}
	return (str);
}
