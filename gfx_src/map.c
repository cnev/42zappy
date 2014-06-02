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

char			*strip_newline(char *str)
{
	char			*ret;

	ret = strdup(str);
	if (ret[strlen(ret) - 1] != '\n')
		return (NULL);
	ret[strlen(ret) - 1] = '\0';
	return (ret);
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
	i = -1;
	while (++i < MAP->map_y)
	{
		j = -1;
		while (++j < MAP->map_x)
			printf("x");
		printf("\n");
	}
	return (0);
}

int				input_cell_contents(char *contents)
{
	char			**av;
	char			*data;
	int				x;
	int				y;
	int				findings[7];


	data = strip_newline(contents);
	av = ft_strsplit(data, ' ');
	x = atoi(av[1]);
	y = atoi(av[2]);
	findings[0] = atoi(av[3]);
	findings[1] = atoi(av[4]);
	findings[2] = atoi(av[5]);
	findings[3] = atoi(av[6]);
	findings[4] = atoi(av[7]);
	findings[5] = atoi(av[8]);
	findings[6] = atoi(av[9]);
	memcpy(MAP->grid[y][x].contents, findings, sizeof(int) * 7);
	return (0);
}
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
int				input_mapdata(char *mapdata)
{
	char			**av;
	char			*data;

	data = strip_newline(mapdata);
	av = ft_strsplit(data, ' ');
	MAP->map_x = atoi(av[1]);
	MAP->map_y = atoi(av[2]);
	if (MAP->map_x < 0 || MAP->map_y < 0)
		return (print_exit("Invalid map size"));
	init_map();
	input_cell_contents("bct 0 0 1 1 1 1 1 1 1\n");
	input_cell_contents("bct 0 1 1 1 1 1 1 1 1\n");
	//input_new_player("pnw #1 1 1 1 1 bob\n");
	MAP->grid[0][0].player = (t_player *)malloc(sizeof(t_player));
	MAP->grid[2][4].player = (t_player *)malloc(sizeof(t_player));
	MAP->grid[1][5].player = (t_player *)malloc(sizeof(t_player));
	int i = -1;
	int j;
	while (++i < MAP->map_y)
	{
		j = -1;
		while (++j < MAP->map_x)
		{
			if (MAP->grid[i][j].player)
				printf("i");
			if (MAP->grid[i][j].contents[0] != 0)
				printf("o");
			else
				printf("x");
		}
		printf("\n");
	}
	return (0);
}



