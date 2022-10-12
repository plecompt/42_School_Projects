/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plecompt <plecompt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 14:14:21 by plecompt          #+#    #+#             */
/*   Updated: 2015/04/01 14:23:18 by plecompt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	if (str)
	{
		i = 0;
		len = ft_strlen(str);
		while (i < len / 2)
		{
			tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
			i++;
		}
	}
	return (str);
}
