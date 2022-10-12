/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:35:55 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 17:05:02 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*tmp;

	if (!s)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		exit(0);
	return (tmp = ft_strcpy(tmp, s));
}
