/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 22:38:05 by kberger           #+#    #+#             */
/*   Updated: 2014/03/07 16:32:09 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*freshcat;

	if (!s1 || !s2)
		return (NULL);
	freshcat = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!freshcat)
		return (freshcat);
	freshcat = ft_strcat(freshcat, s1);
	freshcat = ft_strcat(freshcat, s2);
	return (freshcat);
}
