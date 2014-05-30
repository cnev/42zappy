/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:06:20 by cnev              #+#    #+#             */
/*   Updated: 2014/05/30 16:06:21 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int				print_usage(void)
{
	dprintf(2, "Usage: ./gfx -p <port> [-h <hostname>]\n");
	dprintf(2, "\t-p port\n");
	dprintf(2, "\t-h nom de la machine hote, par defaut c'est le localhost\n");
	return (0);
}

int				print_exit(char *msg)
{
	dprintf(2, "%s\n", msg);
	exit(1);
	return (0);
}
