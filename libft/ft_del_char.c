/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:27:35 by cchevall          #+#    #+#             */
/*   Updated: 2014/03/07 18:37:52 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_del_char(char *str, size_t pos)
{
	char			*p_str;
	char			*tmp;
	size_t			i;

	i = 0;
	tmp = ft_strdup(str);
	if (!tmp)
		return (NULL);
	p_str = str;
	while (i < pos)
	{
		p_str[i] = tmp[i];
		i++;
	}
	while (i < ft_strlen(tmp))
	{
		p_str[i] = tmp[i + 1];
		i++;
	}
	p_str[i] = '\0';
	free(tmp);
	return (str);
}
