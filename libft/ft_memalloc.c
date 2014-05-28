/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 23:02:29 by kberger           #+#    #+#             */
/*   Updated: 2014/05/13 17:33:28 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*memory;
	size_t			i;

	memory = (unsigned char*)malloc(size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < size)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
