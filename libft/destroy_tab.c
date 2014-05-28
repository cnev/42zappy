/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:39:16 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/25 13:14:37 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	**destroy_tab(char **tab_char, size_t size)
{
	size_t		i;

	i = 0;
	if (tab_char != NULL)
	{
		while (i < size)
		{
			if ((tab_char)[i] != NULL)
			{
				free((tab_char)[i]);
				(tab_char)[i] = NULL;
			}
			i++;
		}
		free(tab_char);
		tab_char = NULL;
	}
	return (tab_char);
}
