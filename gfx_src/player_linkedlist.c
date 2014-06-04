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
/*
typedef struct	s_player
{
	int				id;
	char			*team;
	int				pos_x;
	int				pos_y;
	int				lv;
	int				o;
}					t_player;

typedef struct	s_list_player
{
	t_player		*player;
	s_list_player	*next;
}					t_list_player;

t_list_player	*create_elem(char *data)
{
	t_list_player	*elem;
	char			**msg;

	msg = ft_strsplit(data, ' ');
	elem = (t_list_player *)malloc(sizeof(t_list_player));
	elem->player->id = atoi(msg[0]);
	elem->player->team = ft_strdup(msg[1]);
	elem->player->pos_x = atoi(msg[2]);
	elem->player->pos_y = atoi(msg[3]);
	elem->player->lv = atoi(msg[4]);
	elem->player->o = atoi(msg[5]);
	elem->next = NULL;
	return (elem);
}

int				list_size(t_list_player *first)
{
	t_list_player	*tmp;
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

void			pushback(t_list_player **first, char *data)
{
	t_list_player	*tmp;
	t_list_player	*new_elem;

//printf("data = %s\n", data);
	if (!(*first))
		*first = create_elem(data);
	else
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		new_elem = create_elem(data);
		tmp->next = new_elem;
//		printf("pushed\n");
	}
}*/

/*void			delete_list(t_list_player **first)
{
	t_list_player	*tmp;
	t_list_player	*prev;

	if (!*first)
	{
		return ;
	}
	prev = *first;
	tmp = (*first)->next;
	while (prev)
	{
		free(prev->data);
		free(prev);
		prev = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	*first = NULL;
}*/
/*
void			show_list(t_list_player *first)
{
	t_list_player	*tmp;
	int				i;

	i = 0;
	if (first == NULL)
		return ;
	tmp = first;
	while (tmp)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("]: ");
		ft_putendl(tmp->data);
		tmp = tmp->next;
		i++;
	}
}
*/
