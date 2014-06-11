/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 17:34:20 by cnev              #+#    #+#             */
/*   Updated: 2014/06/02 17:34:21 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static int		render_land(SDL_Renderer *ren)
{
	int				i = -1;
	int				j;
	SDL_Texture		*background = load_texture("img/fond_vert.bmp", ren);

	while (++i < MAP->map_y)
	{
		j = -1;
		while (++j < MAP->map_x)
		{
			render_texture(background, ren, CELL_W * j, CELL_H * i);
		}
	}
	return (0);
}

int				bury_ore(int x, int y, int ore_type, int ore_nb)
{
	MAP->grid[y][x].contents[ore_type] = ore_nb;
	return (0);
}

static int		render_ore(SDL_Renderer *ren)
{
	int				i = -1;
	int				j;
	int				k;

	SDL_Texture		*background = load_texture("img/pioche.bmp", ren);
	while (++i < MAP->map_y)
	{
		j = -1;
		while (++j < MAP->map_x)
		{
			k = 0;
			while (++k < 7)
			{
				if (MAP->grid[j][i].contents[k])
				{
					render_texture(background, ren, CELL_W * j, CELL_H * i);
				}
			}
		}
	}
	return (0);
}

static int		render_player(SDL_Renderer *ren)
{
	SDL_Texture		*background = load_texture("img/cercletamere.bmp", ren);
	t_pl			*tmp;

	tmp = MAP->players;
	while (tmp)
	{
		render_texture(background, ren, CELL_W * tmp->pos_x, CELL_H * tmp->pos_y);
		tmp = tmp->next;
	}
	return (0);
}

static int		render_police(SDL_Renderer *ren, SDL_Surface *text)
{
	SDL_Texture		*texture = SDL_CreateTextureFromSurface(ren, text);
	render_texture(texture, ren, 0, 0);
	return (0);
}

int				bobone(SDL_Renderer *renderer, SDL_Renderer *renderer2)
{
	SDL_RenderClear(renderer);
	SDL_RenderClear(renderer2);
	//renderTexture(background, renderer, 0, 0);
	//renderTexture(background, renderer, 400, 400);
	render_land(renderer);
	render_player(renderer);
	render_ore(renderer);
	render_police(renderer2, prepare_ttf(renderer2));
	SDL_RenderPresent(renderer);
	SDL_RenderPresent(renderer2);
	return (0);
}
