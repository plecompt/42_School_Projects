/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:49:54 by plecompt          #+#    #+#             */
/*   Updated: 2017/04/04 13:49:56 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	if (!lst)
		return ;
	prev = NULL;
	cur = NULL;
	cur = *lst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		next = NULL;
	}
	*lst = prev;
}
