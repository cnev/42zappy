/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 11:08:16 by kberger           #+#    #+#             */
/*   Updated: 2014/03/07 16:34:02 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ns;
	size_t		i;

	ns = ft_strnew(len + 1);
	i = 0;
	if (!ns || !s)
		return (NULL);
	while (len)
	{
		ns[i] = s[start + i];
		i++;
		len--;
	}
	ns[i] = '\0';
	return (ns);
}
