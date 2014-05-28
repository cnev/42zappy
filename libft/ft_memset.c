/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 15:34:03 by kberger           #+#    #+#             */
/*   Updated: 2014/03/25 21:38:46 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (len--)
	{
		s[len] = (unsigned char)c;
	}
	return (str);
}
