/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:47:36 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/21 16:17:54 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nlen(int n)
{
	int			len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_itoa_neg(int n, int nb, int len, char *str)
{
	if (n == -2147483648)
	{
		n = 2147483647;
		str[0] = '-';
		len--;
		nb = n % 10;
		n = n / 10;
		str[len] = nb + '1';
		len--;
	}
	else
	{
		n = -n;
		str[0] = '-';
		len--;
	}
	while (len > 0)
	{
		nb = n % 10;
		n = n / 10;
		str[len] = nb + '0';
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			nb;
	int			len;
	char		*str;

	nb = 0;
	len = ft_nlen(n);
	str = (char *)malloc((len + 1) * sizeof(str));
	str[len + 1] = '\0';
	if (n < 0)
		str = ft_itoa_neg(n, nb, len, str);
	else if (n == 0)
		str[0] = '0';
	else
	{
		len--;
		while (len >= 0)
		{
			nb = n % 10;
			n = n / 10;
			str[len] = nb + '0';
			len--;
		}
	}
	return (str);
}
