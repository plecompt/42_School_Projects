/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:08:56 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/24 11:49:19 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_file_to_tab(char *file)
{
	char		**tab;
	char		*tmp;

	tab = NULL;
	if ((tmp = ft_file_to_char(file)) == NULL)
		return (NULL);
	if ((tab = ft_strsplit(tmp, '\n')) == NULL)
		return (NULL);
	free(tmp);
	return (tab);
}
