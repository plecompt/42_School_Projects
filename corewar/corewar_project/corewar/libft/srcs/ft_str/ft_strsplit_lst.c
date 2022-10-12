/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:50:37 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/10 16:14:44 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_dup_word(char const *s, char c)
{
	char		*word;
	t_list		*lst;
	int			len;
	int			i;

	len = 0;
	lst = NULL;
	while (s[len] && s[len] != c)
		len++;
	if (!(word = ft_memalloc(len + 1)))
		exit(0);
	i = -1;
	while (++i < len)
		word[i] = s[i];
	word[i] = '\0';
	lst = ft_lstnew(word, len);
	return (lst);
}

t_list				*ft_strsplit_lst(char const *s, char c)
{
	t_list		*lst_first;
	t_list		*lst;

	lst_first = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (lst_first == NULL)
			{
				lst_first = ft_dup_word(s, c);
				lst = lst_first;
			}
			else
			{
				lst->next = ft_dup_word(s, c);
				lst = lst->next;
			}
		}
		while (*s && *s != c)
			s++;
	}
	return (lst_first);
}
