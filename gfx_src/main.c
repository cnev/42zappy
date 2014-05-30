/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:51:31 by cnev              #+#    #+#             */
/*   Updated: 2014/05/29 17:51:32 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
/*
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("PABON");
	SDL_Window      *win;
	SDL_Window      *win2;
	SDL_Event       event;
	//SDL_Texture     *tex;
	SDL_Renderer    *rd;
	SDL_Renderer    *rd2;
	//SDL_Point       *p;
	//Uint32				*texturebuf;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &win, &rd);
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &win2, &rd2);
	while (42)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_DestroyWindow(win);
			SDL_DestroyWindow(win2);
			SDL_Quit();
			exit(0);
		}
	}
	*/

int				main(int ac, char **av)
{
	if (ac != 3 && ac != 5)
		return (print_usage());
	if (start_gfx(ac, av) < 0)
		return (-1);
	return (0);
}
