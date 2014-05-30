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

OBJ3 = $(subst .c,.o,$(SRC3))
LDFLAGS = `SDL2/bin/sdl2-config --cflags --libs`

all: SDL2 $(NAME3)

$(NAME3): $(OBJ3)
	make -C ../libft
	gcc -Wall -Wextra -Werror -o $(NAME3) $(OBJ3) -O3 -L../libft -lft $(LDFLAGS) \
	-I includes

%.o:%.c
	gcc -Wall -Wextra -Werror -O3 -c -o $@ $^ -I. -I includes

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
	tar xf SDL2-2.0.3.tar.gz
	( cd SDL2-2.0.3 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.3.tar.gz SDL2-2.0.3 SDL2/junk

SDL:
	mkdir -p SDL2/junk
	tar xvf SDL2-2.0.3.tar.gz
	( cd SDL2-2.0.3 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.3.tar.gz SDL2-2.0.3 SDL2/junk
