/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:35:38 by cchevall          #+#    #+#             */
/*   Updated: 2014/03/07 18:37:33 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_stradd(char *s1, const char *s2, size_t pos)
{
	char			*tmp;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	tmp = ft_strcpy(tmp, s1);
	while (i < pos)
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	while (tmp[i - ft_strlen(s2)] != '\0')
	{
		s1[i] = tmp[i - ft_strlen(s2)];
		i++;
	}
	free(tmp);
	return (s1);
}
