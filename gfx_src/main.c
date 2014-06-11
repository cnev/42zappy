/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:51:31 by cnev              #+#    #+#             */
/*   Updated: 2014/05/29 17:51:32 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static int		msq_init(void)
{
	int				msqid;
	key_t			key;

	if ((key = ftok("gfx.c", 'A')) == -1)
	{
		perror("ftok");
		exit(1);
	}
	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1)
	{
		perror("msgget");
		exit(1);
	}
	if ((key = ftok("message_id.c", 'B')) == -1)
	{
		perror("ftok");
		exit(1);
	}
	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1)
	{
		perror("msgget");
		exit(1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	int				pid;

	if (ac != 3 && ac != 5)
		return (print_usage());
	msq_init();
	pid = fork();
	if (!pid)
		start_message_receiver(ac, av);
	else if (start_gfx(ac, av) < 0)
		return (-1);
	return (0);
}
