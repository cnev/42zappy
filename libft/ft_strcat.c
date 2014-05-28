/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 00:16:32 by kberger           #+#    #+#             */
/*   Updated: 2014/03/07 16:19:07 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*p_s;
	unsigned char	*p_d;

	p_s = (unsigned char *)s2;
	p_d = (unsigned char *)s1;
	i = ft_strlen(s1);
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (p_s[j] != '\0')
	{
		p_d[i] = p_s[j];
		i++;
		j++;
	}
	p_d[i] = '\0';
	return (s1);
}
