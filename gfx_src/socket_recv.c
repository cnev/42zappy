/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_recv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:02:19 by cnev              #+#    #+#             */
/*   Updated: 2014/06/02 18:02:20 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static char		*strip_newline(char *str)
{
	char			*ret;

	ret = strdup(str);
	if (ret[strlen(ret) - 1] != '\n')
		return (NULL);
	ret[strlen(ret) - 1] = '\0';
	return (ret);
}

char			**process_message(char *message)
{
	char			**tab;
	char			*data;

	if (!message)
		return (NULL);
	data = strip_newline(message);
	tab = ft_strsplit(data, ' ');
	free(data);
	return (tab);
}
