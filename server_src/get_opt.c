/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 20:37:07 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/27 18:25:39 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/server.h"

int				get_opt_int(int ac, char **av, char *opt)
{
	int			opt;
	int			i;

	i = 1;
	opt = 0;
	while (i < ac)
	{
		if (!strcmp(av[i], opt) && av[i + 1] && is_digit(av[i + 1]))
		{
			opt = ft_atoi(av[i + 1]);
			return (opt);
		}
		i++;
	}
	return (ERROR);
}
