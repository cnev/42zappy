/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 15:53:30 by cchevall          #+#    #+#             */
/*   Updated: 2014/03/07 18:35:28 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd_sub(char *str, int fd, int size)
{
	while (str[size] != '\0')
	{
		ft_putchar_fd(str[size], fd);
		size++;
	}
}
