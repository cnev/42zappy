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
	memcpy(MAP->grid[y][x].contents, findings, sizeof(int) * 7);
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
