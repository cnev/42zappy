/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:18:44 by cnev              #+#    #+#             */
/*   Updated: 2014/05/30 16:18:45 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int				start_gfx(int ac, char **av)
{
	int				port;
	char			*host;

	if (get_port(ac, av, &port) < 0)
		return (-1);
	if (get_hostname(ac, av, &host) < 0)
		return (-1);
	input_mapdata("msz 10 5\n");
	return (0);
}
