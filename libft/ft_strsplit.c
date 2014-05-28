/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:21:10 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/23 20:47:46 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		countchar(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		countword(char const *s, char c)
{
	unsigned int	nb;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	nb = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		len = countchar(s + i, c);
		if (len)
		{
			nb++;
			i += len;
		}
		else
			i++;
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**ret;
	unsigned int	i;
	unsigned int	nbword;
	unsigned int	nbchr;

	i = 0;
	nbword = 0;
	ret = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (s == 0)
		return (NULL);
	while (s[i])
	{
		nbchr = countchar(s + i, c);
		if (nbchr)
		{
			ret[nbword] = ft_strsub(s, i, nbchr);
			nbword++;
			i += nbchr;
		}
		else
			i++;
	}
	ret[nbword] = '\0';
	return (ret);
}
