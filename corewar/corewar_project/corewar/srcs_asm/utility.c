/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hivian <hivian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:00:16 by hivian            #+#    #+#             */
/*   Updated: 2017/04/03 16:31:51 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				label_exist(char *str, t_env *e)
{
	t_node		*label;

	label = e->labels->head;
	if (!label)
		return (0);
	while (label)
	{
		if (ft_strequ(str, label->name))
			return (1);
		label = label->next;
	}
	return (0);
}

int				ft_isnumber(char *str)
{
	int			i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char			*trim_quotes(char const *s)
{
	char		*str;
	int			len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] == '"')
		i++;
	len = ft_strlen(s);
	while (s[len - 1] == '"')
		len--;
	while (i < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

int				strchr_comment(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != '#' && s[i] != ';')
		i++;
	if (s[i] == '#' || s[i] == ';')
		return (i);
	else
		return (-1);
}
