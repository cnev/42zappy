/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_linkedlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:16:12 by cnev              #+#    #+#             */
/*   Updated: 2014/06/02 18:16:13 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static t_pl			*new_pl(char **data)
{
	t_pl			*elem;

	elem = (t_pl *)malloc(sizeof(t_pl));
	elem->id = atoi(data[1] + 1);
	elem->team = strdup(data[6]);
	elem->pos_x = atoi(data[2]);
	elem->pos_y = atoi(data[3]);
	elem->lv = atoi(data[4]);
	elem->o = atoi(data[5]);
	elem->next = NULL;
	return (elem);
}

int				pl_size(t_pl *first)
{
	t_pl	*tmp;
	int				i;

	i = 0;
	tmp = first;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void			pushback_pl(t_pl **first, char **data)
{
	t_pl	*tmp;
	t_pl	*new_elem;

	if (!(*first))
		*first = new_pl(data);
	else
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		new_elem = new_pl(data);
		tmp->next = new_elem;
	}
}
