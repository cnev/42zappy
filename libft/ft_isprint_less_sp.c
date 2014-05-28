/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_less_sp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 09:50:22 by kberger           #+#    #+#             */
/*   Updated: 2014/03/07 16:04:25 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		isprint_less_sp(int c)
{
	if (c >= 32 && c <= 126 && c != 32)
		return (1);
	else
		return (0);
}