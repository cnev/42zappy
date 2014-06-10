/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 10:19:13 by cnev              #+#    #+#             */
/*   Updated: 2014/06/03 10:19:14 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int				msg_is_msz(char **data)
{
	if (!strcmp(data[0], "msz"))
	{
		input_mapdata(data);
		init_map();
		return (TRUE);
	}
	return (FALSE);
}

int				msg_is_bct(char **data)
{
	if (!strcmp(data[0], "bct"))
	{
		input_cell_contents(data);
		return (TRUE);
	}
	return (FALSE);
}

int				msg_is_pnw(char **data)
{
	if (!strcmp(data[0], "pnw"))
	{
		input_cell_contents(data);
		return (TRUE);
	}
	return (FALSE);
}

int				msg_is_pmv(char **data)
{
	if (!strcmp(data[0], "pmv"))
	{
		move_player(data);
		return (TRUE);
	}
	return (FALSE);
}

static int		(*g_msg[])(char **) =
	{
		&msg_is_msz, &msg_is_bct, msg_is_pmv, NULL
	};

int				id_message(char **data)
{
	int				i;

	if (!data)
		return (-1);
	i = -1;
	while (g_msg[++i])
	{
		if ((g_msg[i])(data) == TRUE)
			return (0);
	}
	return (print_exit("Unidentified transmission couldn't be processed."));
}
