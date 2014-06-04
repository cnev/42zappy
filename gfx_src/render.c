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
	SDL_Texture		*background = load_texture("fond_vert.bmp", ren);

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

static int		render_player(SDL_Renderer *ren)
{
	int				i = -1;
	int				j;

	SDL_Texture		*background = load_texture("cercletamere.bmp", ren);

	while (++i < MAP->map_y)
	{
		j = -1;
		while (++j < MAP->map_x)
		{
			if (MAP->grid[j][i].player)
				render_texture(background, ren, CELL_W * j, CELL_H * i);
		}
	}
	return (0);
}

static int		render_police(SDL_Renderer *ren, SDL_Surface *text)
{
	SDL_Texture		*texture = SDL_CreateTextureFromSurface(ren, text);
	render_texture(texture, ren, 0, 0);
	return (0);
}

int				bobone(SDL_Window *window)
{

	SDL_Window		*window2;

	window2 = SDL_CreateWindow("Test SDL 2.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer	*renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Renderer	*renderer2 = SDL_CreateRenderer(window2, -1, 0);
	SDL_RenderClear(renderer);

	//renderTexture(background, renderer, 0, 0);
	//renderTexture(background, renderer, 400, 400);
	render_land(renderer);
	render_player(renderer);
	render_police(renderer2, prepare_ttf(renderer2));
	SDL_RenderPresent(renderer);
	SDL_RenderPresent(renderer2);
	return (0);
}
