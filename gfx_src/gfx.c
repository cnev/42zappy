/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:18:44 by cnev              #+#    #+#             */
/*   Updated: 2014/05/30 16:18:45 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"



int				start_gfx(int ac, char **av)
{
	int				port;
	char			*host;

	if (get_port(ac, av, &port) < 0)
		return (-1);
	if (get_hostname(ac, av, &host) < 0)
		return (-1);
	dummy_testing_input();
	SDL_Window		*window;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1200, SDL_WINDOW_SHOWN);
	SDL_Window		*window2;
	window2 = SDL_CreateWindow("Test SDL 2.1", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Event		evenements;
	TTF_Init();
	//SDL_Texture		*texture = SDL_CreateTextureFromSurface(renderer, image);
	//SDL_Rect dest = { 640/2 - image->w/2,480/2 - image->h/2, image->w, image->h};
	//SDL_RenderCopy(renderer,texture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer
	//SDL_RenderPresent(renderer); // Affichage
	// SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

	// SDL_DestroyTexture(texture); // Libération de la mémoire associée à la texture
	SDL_Renderer	*renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Renderer	*renderer2 = SDL_CreateRenderer(window2, -1, 0);
	while(1)
	{
		SDL_WaitEvent(&evenements);
		bobone(renderer, renderer2);
		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			break ;
		if(evenements.type == SDL_MOUSEBUTTONDOWN)
		{
			printf("WID %d\n", evenements.button.windowID);
			MAP->grid[7][7].player = (t_pl *)malloc(sizeof(t_pl));
		}
	}
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	return (0);
}
