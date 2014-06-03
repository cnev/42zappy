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
	printf("Job's done !\n");
	SDL_Window		*window;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1200, SDL_WINDOW_SHOWN);
	// Variables

	SDL_Event		evenements;
	int				terminer = 0;

	//SDL_Texture		*texture = SDL_CreateTextureFromSurface(renderer, image);
	//SDL_Rect dest = { 640/2 - image->w/2,480/2 - image->h/2, image->w, image->h};
	//SDL_RenderCopy(renderer,texture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer
	//SDL_RenderPresent(renderer); // Affichage
	// SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

	// SDL_DestroyTexture(texture); // Libération de la mémoire associée à la texture
	bobone(window);
	while(!terminer)
	{
		SDL_WaitEvent(&evenements);
		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
