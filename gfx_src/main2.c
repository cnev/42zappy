/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:15:50 by cnev              #+#    #+#             */
/*   Updated: 2014/06/09 16:15:51 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>

int				server_init(int port)
{
	int					s;
	struct sockaddr_in	sin;
	struct protoent		*pe;

	pe = getprotobyname("tcp");
	s = socket(PF_INET, SOCK_STREAM, pe->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	bind(s, (struct sockaddr*)&sin, sizeof(sin));
	listen(s, 42);
	return (s);
}

int				main(int ac, char **av)
{
	int					fd;
	char				buf[1024];
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;
	int					xox;

	fd = server_init(atoi(av[1]));
	csin_len = sizeof(csin);
	cs = accept(fd, (struct sockaddr*)&csin, &csin_len);
	//write(cs, "BIENVENUE\n", strlen("BIENVENUE\n"));
	while (1)
	{
		xox = read(0, buf, 1023);
		buf[xox] = 0;
		write(cs, buf, xox);
	}
	return (0);
}
