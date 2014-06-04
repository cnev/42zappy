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

all: SDL2 $(NAME3)

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

re: fclean all

.PHONY: clean fclean re

SDL2:
	mkdir -p SDL2/junk
	curl -o sdl2.tar.gz http://www.libsdl.org/release/SDL2-2.0.3.tar.gz
	tar xf sdl2.tar.gz
	( cd SDL2-2.0.3 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.3.tar.gz SDL2-2.0.3 SDL2/junk

SDL2i:
	mkdir -p SDL2img/junk
	( cd SDL2_image \
		&& ./configure OBJC=clang CC=gcc --prefix=$(shell pwd)/SDL2img/ \
		&& $(MAKE) && $(MAKE) install )

SDL2t:
	mkdir -p SDL2ttf/junk
	( cd SDL2_ttf \
		&& ./configure OBJC=clang CC=gcc --prefix=$(shell pwd)/SDL2ttf \
		&& $(MAKE) && $(MAKE) install )

SDL:
	mkdir -p SDL2/junk
	tar xvf SDL2-2.0.3.tar.gz
	( cd SDL2-2.0.3 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.3.tar.gz SDL2-2.0.3 SDL2/junk
