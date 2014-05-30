/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:23:02 by cnev              #+#    #+#             */
/*   Updated: 2014/05/30 16:23:03 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static int		find_in_argv(int ac, char **av, int *select, char *key)
{
	int				i;

	i = -1;
	while (++i < ac)
	{
		if (!strcmp(key, av[i]))
		{
			if (i + 1 < ac)
			{
				*select = i + 1;
				return (0);
			}
			else
				return (-1);
		}
	}
	return (-1);
}

static int		scan_port(int select, char **av)
{
	int				i;

	i = -1;
	while (av[select][++i])
	{
		if (!isdigit(av[select][i]))
			return (-1);
	}
	return (0);
}

static int		fetch_port(int select, char **av, int *port)
{
	int				nb;

	nb = atoi(av[select]);
	if (nb < 1 || nb > 65535)
		return (-1);
	*port = nb;
	return (0);
}

int				get_port(int ac, char **av, int *port)
{
	int				select;
	int				nb;

	if (find_in_argv(ac, av, &select, "-p") < 0)
		return (-1);
	if (scan_port(select, av) < 0)
		return (-1);
	if (fetch_port(select, av, &nb) < 0)
		return (-1);
	*port = nb;
	dprintf(1, "Port detected: [%d]\n", *port);
	return (0);
}

int				get_hostname(int ac, char **av, char **host)
{
	int				select;

	if (find_in_argv(ac, av, &select, "-h") < 0)
	{
		*host = strdup("localhost");
		dprintf(1, "Hostname detected: [%s]\n", *host);
		return (0);
	}
	*host = strdup(av[select]);
	dprintf(1, "Hostname detected: [%s]\n", *host);
	return (0);
}
