/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 18:55:06 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/27 18:25:41 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/server.h"

int				usage(void)
{
	ft_putstr_fd(USAGE1, 2);
	ft_putstr_fd(USAGE2, 2);
	return (ERROR);
}

char			**get_opt(int ac, char **av)
{
	char		**opt;

}

int				zappy(int ac, char **av)
{

	return (0);
}

int				main(int ac, char **av)
{
	if (ac == 1)
		return (usage());
	ft_puttab_fd(av, 1);
	return(zappy(ac, av));
}
