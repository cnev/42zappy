/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 15:55:52 by cchevall          #+#    #+#             */
/*   Updated: 2014/03/07 18:35:31 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_puttab_fd(char **tabl, size_t fd)
{
	size_t		i;

	i = 0;
	while (i < ft_tablen(tabl))
	{
		ft_putstr_fd(tabl[i], fd);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
