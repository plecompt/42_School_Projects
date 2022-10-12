/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:42:58 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 16:04:01 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(tmp = (char*)ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		tmp[i] = f(s[i]);
	return (tmp);
}
