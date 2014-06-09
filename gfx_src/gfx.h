/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:58:49 by cnev              #+#    #+#             */
/*   Updated: 2014/05/29 17:58:50 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H
# include <stdio.h>
# include "SDL2/include/SDL2/sdl.h"
# include "SDL2img/include/SDL2/SDL_image.h"
# include "SDL2ttf/include/SDL2/SDL_ttf.h"
# include "../includes/libft.h"
# define MAP (map_singleton())
# define TRUE		1
# define FALSE		0
# define LIN		10
# define COL		10
# define SCN_W		1200
# define SCN_H		1200
# define CELL_W		120
# define CELL_H		120


/*
**	print.c
*/
int				print_usage(void);
int				print_exit(char *msg);

/*
**	argv.c
*/
int				get_port(int ac, char **av, int *port);
int				get_hostname(int ac, char **av, char **host);

/*
**	gfx.c
*/
int				start_gfx(int ac, char **av);


typedef struct		s_player
{
	int				id;
	char			*team;
	int				pos_x;
	int				pos_y;
	int				lv;
	int				o;
}					t_player;

typedef struct		s_pl
{
	int				id;
	struct s_pl		*next;
}					t_pl;

typedef struct		s_cell
{
	int				contents[7];
	t_pl			*player;
}					t_cell;
typedef struct		s_map
{
	int				map_x;
	int				map_y;
	t_cell			**grid;
	t_pl			*player;
	int				click_x;
	int				click_y;
}					t_map;
/*
**	map.c
*/
t_map			*map_singleton(void);
int				init_map(void);
int				input_mapdata(char **data);
int				input_cell_contents(char **data);
int				dummy_testing_input(void);

/*
**	sdl_functions.c
*/
SDL_Texture		*load_texture(char *file, SDL_Renderer *ren);
void			render_texture(SDL_Texture *t, SDL_Renderer *r, int x, int y);

/*
**	render.c
*/
int				bobone(SDL_Renderer *window, SDL_Renderer *window2);
int		bury_ore(int x, int y, int ore_type, int ore_nb);

/*
**	socket_recv.c
*/
char			**process_message(char *message);

/*
**	message_id.c
*/
int				id_message(char **data);

/*
**	ttf.c
*/
SDL_Surface		*prepare_ttf(SDL_Renderer *ren);


#endif
