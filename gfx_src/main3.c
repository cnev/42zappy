/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 21:23:23 by cnev              #+#    #+#             */
/*   Updated: 2014/06/09 21:23:24 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static int		socket_client(char *host, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-2);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
		return (-3);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(host);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (-1);
	return (sock);
}

static void		run_receiver(int fd)
{
	struct my_msgbuf	buf;
	int					msqid;
	key_t				key;
	FILE				*file;

	if ((key = ftok("gfx.c", 'A')) == -1)
	{
		perror("ftok");
		exit(1);
	}
	if ((msqid = msgget(key, 0644)) == -1)
	{
		perror("msgget");
		exit(1);
	}
	file = fdopen(fd, "r");
	while (fgets(buf.mtext, sizeof(buf.mtext), file) != NULL)
	{
		int len = strlen(buf.mtext);
		printf("MESSAGE SENT: %s\n", buf.mtext);
		if (msgsnd(msqid, &buf, len + 1, 0) == -1)
			perror("msgsnd");
	}
	if (msgctl(msqid, IPC_RMID, NULL) == -1)
	{
		perror("msgctl");
		exit(1);
	}
	exit(1);
}

static void		run_transmitter(int fd)
{
	struct my_msgbuf	buf;
	int					msqid;
	key_t				key;

	if ((key = ftok("message_id.c", 'B')) == -1)
	{
		perror("ftok");
		exit(1);
	}
	if ((msqid = msgget(key, 0644)) == -1)
	{
		perror("msgget");
		exit(1);
	}
	while (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, IPC_NOWAIT) != -1)
	{
		printf("Message received: %s\n", buf.mtext);
		if (!strncmp(buf.mtext, "end of game\n", 11))
			exit(0);
		write(fd, buf.mtext, strlen(buf.mtext));
	}
	exit(0);
}

static int		run_kirk(char *host, int port)
{
	int					pid;
	int					fd;

	if (!host)
		host = strdup("127.0.0.1");
	fd = socket_client(host, port);
	if (fd == -1)
		return (-1);
	pid = fork();
	if (!pid)
		run_receiver(fd);
	else
		run_transmitter(fd);
	exit(0);
}

int				start_message_receiver(int ac, char **av)
{
	if (ac == 3)
		run_kirk(NULL, atoi(av[2]));
	else
		run_kirk(av[4], atoi(av[2]));
	return (0);
}
