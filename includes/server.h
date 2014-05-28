/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 18:56:31 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/27 18:25:33 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/select.h>

# define USAGE1				"Usage: ./serveur -p <port> -x <width> -y <height> "
# define USAGE2				"-n <team> [<team>] [<team>] ... -c <nb> -t <t>\n"

# define TRUE				1
# define FALSE				0
# define ERROR				-1

# define FD_FREE			0
# define FD_SERV			1
# define FD_CLIENT			2
# define BUF_SIZE			4096
# define MAX(a,b)			((a > b) ? a : b)

/*
** Tortorian (client) ressources;
*/
typedef struct				s_rsrces
{
	int						food;
	int						lin;
	int						der;
	int						sib;
	int						men;
	int						phi;
	int						thy;
}							t_rsrces;
/*
** List of clients;
*/
typedef struct				s_clientlst
{
	int						socket;
	int						alive;
	char					*team;
	int						x;
	int						y;
	int						pov;
	int						level;
	t_rsrces				rsrces;
	struct s_teamlst		*next;
}							t_clientlst;
/*
** Map contents, each element of the list is defined by a position;
** At this position can be found amounts of ressources;
** ttrians: list of the trantorians on map at position x / y;
*/
typedef struct				s_maplst
{
	int						food;
	int						lin;
	int						der;
	int						sib;
	int						men;
	int						phi;
	int						thy;
	int						x;
	int						y;
	char					*ttrians;
	struct s_maplst			*next;
}							t_maplst;
/*
** Trantor world;
*/
typedef struct				s_trantor
{
	int						width;
	int						height;
	int						max_team;
	int						time_u;
	t_clientlst				*fst_client;
}							t_trantor;
/*
** File descriptor structure;
*/
typedef struct				s_fd
{
	int						type;
	void					(*fct_read)();
	void					(*fct_write)();
	char					buf_read[BUF_SIZE + 1];
	char					buf_write[BUF_SIZE + 1];
}							t_fd;
/*
** Server parameters;
*/
typedef struct				s_env
{
	t_fd					*fds;
	int						port;
	int						maxfd;
	int						max;
	int						r;
	fd_set					fd_read;
	fd_set					fd_write;
}							t_env;

#endif
