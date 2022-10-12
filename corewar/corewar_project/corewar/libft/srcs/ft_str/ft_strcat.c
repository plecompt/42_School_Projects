/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:53 by jsivanes          #+#    #+#             */
/*   Updated: 2017/05/04 17:18:30 by hivian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, char const *src)
{
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = dest;
	tmp_src = (char*)src;
	while (*tmp_dest)
		tmp_dest++;
	while (*tmp_src)
		*tmp_dest++ = *tmp_src++;
	*tmp_dest = '\0';
	return (dest);
}
