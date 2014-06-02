/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 17:34:12 by cnev              #+#    #+#             */
/*   Updated: 2014/06/02 17:34:13 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

SDL_Texture		*load_texture(char *file, SDL_Renderer *ren)
{
	SDL_Texture		*texture;
	SDL_Surface		*image;
	Uint32			colorkey;

	texture = NULL;
	image = IMG_Load(file);
	colorkey = SDL_MapRGB(image->format, 255, 255, 255);
	if (image != NULL)
	{
		SDL_SetColorKey(image, SDL_TRUE, colorkey);
		texture = SDL_CreateTextureFromSurface(ren, image);
		SDL_FreeSurface(image);
	}
	else
		print_exit("load_texture");
	return texture;
}

void			render_texture(SDL_Texture *t, SDL_Renderer *r, int x, int y)
{
	SDL_Rect		dst;

	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(t, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(r, t, NULL, &dst);
}
