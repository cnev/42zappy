/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:50:57 by cnev              #+#    #+#             */
/*   Updated: 2014/05/30 16:50:57 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_map			*map_singleton(void)
{
	static t_map	*map = NULL;

	if (!map)
	{
		if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
			print_exit("Failed to malloc map_singleton");
	}
	return (map);
}

int				init_map(void)
{
	int				i;
	int				j;

	i = -1;
	if ((MAP->grid = (t_cell **)malloc(sizeof(t_cell *) * MAP->map_y)) == NULL)
		return (print_exit("Failed to malloc grid"));
	while (++i < MAP->map_y)
	{
		j = -1;
		if ((MAP->grid[i] = (t_cell *)malloc(sizeof(t_cell) * MAP->map_x)) == NULL)
			return (print_exit("Failed to malloc grid"));
		while (++j < MAP->map_x)
		{
			bzero(MAP->grid[i][j].contents, sizeof(int) * 7);
			MAP->grid[i][j].player = NULL;
		}
	}
	return (0);
}

int				input_cell_contents(char **data)
{
	int				x;
	int				y;
	int				findings[7];

	x = atoi(data[1]);
	y = atoi(data[2]);
	findings[0] = atoi(data[3]);
	findings[1] = atoi(data[4]);
	findings[2] = atoi(data[5]);
	findings[3] = atoi(data[6]);
	findings[4] = atoi(data[7]);
	findings[5] = atoi(data[8]);
	findings[6] = atoi(data[9]);
	memcpy(MAP->grid[x][y].contents, findings, sizeof(int) * 7);
	return (0);
}
/*
int				input_player_lv(char **data)
{

}*/
/*
int				input_new_player(char *msg)
{
	char			**av;
	char			*data;
	int				x;
	int				y;

	data = strip_newline(mapdata);
	av = ft_strsplit(data, ' ');
	return (0);
}
*/

int				locate_before_moving(char **data, int *delta, int *coords)
{
	int				o;

	o = atoi(data[4]);
	if (o == 1)
		delta[1] = 1;
	else if (o == 2)
		delta[0] = -1;
	else if (o == 3)
		delta[1] = -1;
	else if (o == 4)
		delta[0] = 1;
	coords[0] = atoi(data[2]);
	coords[1] = atoi(data[3]);
	coords[2] = coords[0] + delta[0];
	coords[3] = coords[1] + delta[1];
	printf("Moving at %d %d\nSearching at %d %d\n", coords[0], coords[1], coords[2], coords[3]);
	if (MAP->grid[coords[2]][coords[3]].player)
		return (0);
	return (-1);
}

int				move_player(char **data)
{
	int				delta[2] = {0, 0};
	int				coords[4];
	/*
	Move:
		- pmv #n dst_x dst_y dst_o
	*/
	if (locate_before_moving(data, delta, coords) == -1)
		return (-1);
	MAP->grid[coords[2]][coords[3]].player = NULL;
	MAP->grid[coords[0]][coords[1]].player = (t_pl *)malloc(sizeof(t_pl));
	return (0);
}

int				input_mapdata(char **data)
{
	MAP->map_x = atoi(data[1]);
	MAP->map_y = atoi(data[2]);
	if (MAP->map_x < 0 || MAP->map_y < 0)
		return (print_exit("Invalid map size"));
	return (0);
}

int				dummy_testing_input(void)
{
	char			*recv;

	recv = strdup("msz 10 10\n");
	id_message(process_message(recv));
	free(recv);
	recv = strdup("bct 0 0 1 1 1 1 1 1 1\n");
	id_message(process_message(recv));
	free(recv);
	recv = strdup("bct 0 1 1 1 1 1 1 1 1\n");
	id_message(process_message(recv));
	free(recv);
	MAP->grid[0][0].player = (t_pl *)malloc(sizeof(t_pl));
	MAP->grid[2][4].player = (t_pl *)malloc(sizeof(t_pl));
	MAP->grid[1][5].player = (t_pl *)malloc(sizeof(t_pl));
	return (0);
}
