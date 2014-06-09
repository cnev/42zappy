#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/29 17:51:27 by cnev              #+#    #+#              #
#    Updated: 2014/05/29 17:51:28 by cnev             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME3 = gfx

SRC3 += main.c
SRC3 += print.c
SRC3 += gfx.c
SRC3 += argv.c
SRC3 += map.c
SRC3 += sdl_functions.c
SRC3 += render.c
SRC3 += socket_recv.c
SRC3 += player_linkedlist.c
SRC3 += message_id.c
SRC3 += ttf.c

OBJ3 = $(subst .c,.o,$(SRC3))
LDFLAGS = `SDL2/bin/sdl2-config --cflags --libs` -L SDL2img/lib -lSDL2_image \
			-L SDL2ttf/lib -lSDL2_ttf

all: $(NAME3)

$(NAME3): $(OBJ3)
	make -C ../libft
	gcc -Wall -Wextra -Werror -o $(NAME3) $(OBJ3) -O3 -L../libft -lft $(LDFLAGS) \
	-I SDL2/includes/SDL2 -I SDL2ttf/includes/SDL2

%.o:%.c
	gcc -Wall -Wextra -Werror -O3 -c -o $@ $^ -I. -I SDL2/includes/SDL2 -I SDL2ttf/includes/SDL2

clean:
	make -C ../libft clean
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f $(OBJ3)

fclean: clean
	make -C ../libft fclean
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(NAME3)
	rm -rf SDL2
	rm -rf SDL2img
	rm -rf SDL2ttf

re: fclean all

.PHONY: clean fclean re

SDLinstall: SDL2 SDL2i SDL2t

SDL2:
	mkdir -p SDL2/junk
	curl -o sdl2.tar.gz http://www.libsdl.org/release/SDL2-2.0.3.tar.gz
	tar xf sdl2.tar.gz
	( cd SDL2-2.0.3 \
		&& ./configure OBJC=clang CC=clang --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv sdl2.tar.gz SDL2/junk

SDL2i:
	mkdir -p SDL2img/junk
	curl -o sdl2i.tar.gz https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz
	tar xf sdl2i.tar.gz
	( export SDL2_CONFIG=$(PWD)/SDL2/bin/sdl2-config \
		&& cd SDL2_image-2.0.0 \
		&& ./configure OBJC=clang CC=gcc --prefix=$(shell pwd)/SDL2img/ \
		&& $(MAKE) && $(MAKE) install )
	mv sdl2i.tar.gz SDL2/junk
	cp SDL2/include/SDL2/*.h SDL2img/include/SDL2
SDL2t:
	mkdir -p SDL2ttf/junk
	curl -o sdl2.tar.gz https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.12.tar.gz
	tar xf sdl2.tar.gz
	( export SDL2_CONFIG=$(PWD)/SDL2/bin/sdl2-config \
		&& cd SDL2_ttf-2.0.12 \
		&& ./configure OBJC=clang CC=gcc --prefix=$(shell pwd)/SDL2ttf \
		&& $(MAKE) && $(MAKE) install )
	mv sdl2.tar.gz SDL2/junk
	cp SDL2/include/SDL2/*.h SDL2ttf/include/SDL2

SDL:
	mkdir -p SDL2/junk
	tar xvf SDL2-2.0.3.tar.gz
	( cd SDL2-2.0.3 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.3.tar.gz SDL2-2.0.3 SDL2/junk
