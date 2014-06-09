/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 18:33:15 by cnev              #+#    #+#             */
/*   Updated: 2014/06/04 18:33:15 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static char		*get_cell(void)
{
	int				x = MAP->click_x;
	int				y = MAP->click_y;
	char			*str = malloc(1000);

	sprintf(str, "Cell X:%d Y:%d\n", x / 120, y / 120);
	return (str);
}

SDL_Surface		*prepare_ttf(SDL_Renderer *ren)
{
	SDL_RenderClear(ren);
	TTF_Font *police = NULL;
	police = TTF_OpenFont("Arial Bold.ttf", 20);

	SDL_Color couleurNoire = {255, 255, 255, 0};
	SDL_Surface		*texte;
	char		*buf = get_cell();
	texte = TTF_RenderText_Blended_Wrapped(police, buf, couleurNoire, 800);
	TTF_CloseFont(police);
	return (texte);
}
x
