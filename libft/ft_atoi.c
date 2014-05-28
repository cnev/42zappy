/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:09:03 by cchevall          #+#    #+#             */
/*   Updated: 2013/12/03 17:29:51 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		rslt;
	int		sign;
	int		i;

	rslt = 0;
	sign = 0;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\v'
			|| *str == '\n' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		i++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && i <= 1)
	{
		rslt *= 10;
		rslt += *str++ - '0';
	}
	if (sign)
		rslt *= -1;
	return (rslt);
}
