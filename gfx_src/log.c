/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 18:51:18 by cnev              #+#    #+#             */
/*   Updated: 2014/06/10 18:51:19 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_logs			*logs_singleton(void)
{
	static t_logs	*i = NULL;

	if (!i)
		i = (t_logs *)malloc(sizeof(t_logs));
	return (i);
}

static int		new_log(char *msg)
{
	t_log			*new;

	new = (t_log *)malloc(sizeof(t_log));
	new->msg = strdup(msg);
	new->next = NULL;
	return (new);
}

int				pushback_log(char *msg)
{
	t_log			*new;
	t_log			*tmp;

	tmp = LOG->head;
	if (!tmp)
	{
		LOG->head = new_log(msg);
		LOG->tail = LOG->head;
	}
	else
		LOG->tail = new_log(msg);
	return (0);
}
