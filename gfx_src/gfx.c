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

int		receiver_msqid(void)
{
	static int		msqid = 0;
	static int		set = 0;
	key_t key;

	if (!set)
	{
		if ((key = ftok("gfx.c", 'A')) == -1)
		{
			perror("ftok");
			exit(1);
		}
		if ((msqid = msgget(key, 0644)) == -1)
		{
			perror("msgget");
			exit(1);
		}
		set = 1;
	}
	return (msqid);
}

int		transmitter_msqid(void)
{
	key_t key;
	static int		msqid = 0;
	static int		set = 0;

	if (!set)
	{
		if ((key = ftok("message_id.c", 'B')) == -1)
		{
			perror("ftok");
			exit(1);
		}
		if ((msqid = msgget(key, 0644)) == -1)
		{
			perror("msgget");
			exit(1);
		}
		set = 1;
	}
	return (msqid);
}
int				start_gfx(int ac, char **av)
{
	int				port;
	char			*host;

	if (get_port(ac, av, &port) < 0)
		return (-1);
	if (get_hostname(ac, av, &host) < 0)
		return (-1);
	//dummy_testing_input();
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
	int button_down = 0;
	struct my_msgbuf buf;
	MAP->players = NULL;
	while (1)
	{
		while (msgrcv(receiver_msqid(), &buf, sizeof(buf.mtext), 0, IPC_NOWAIT) != -1)
		{
			printf("Message received: %s\n", buf.mtext);
			id_message(process_message(buf.mtext));
		}
		bobone(renderer, renderer2);
		SDL_WaitEvent(&evenements);
		if (evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			break ;
		if (evenements.type != SDL_MOUSEBUTTONDOWN && evenements.type != SDL_MOUSEBUTTONUP)
			continue ;
		else if (evenements.type == SDL_MOUSEBUTTONDOWN)
		{
			button_down = 1;
			MAP->click_x = evenements.button.x;
			MAP->click_y = evenements.button.y;
		}
		else if (evenements.type == SDL_MOUSEBUTTONUP && button_down == 1)
		{
			button_down = 0;
			bury_ore(MAP->click_y / 120, MAP->click_x / 120, 1, 5);
		}
	}
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	return (0);
}
