# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/26 18:51:31 by cchevall          #+#    #+#              #
#    Updated: 2014/05/27 18:25:37 by cchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client

NAME2 = serveur

NAME3 = gfx

SRC1 += client_src/main.c

SRC2 += server_src/main.c

SRC3 += gfx_src/main.c

OBJ1 = $(subst .c,.o,$(SRC1))

OBJ2 = $(subst .c,.o,$(SRC2))

OBJ3 = $(subst .c,.o,$(SRC2))

all: $(NAME1) $(NAME2) $(NAME3)

client: $(NAME1)

serveur: $(NAME2)

visu: $(NAME3)

$(NAME1): $(OBJ1)
	make -C libft
	gcc -Wall -Wextra -Werror -o $(NAME1) $(OBJ1) \
	-L libft -lft -I includes

$(NAME2): $(OBJ2)
	make -C libft
	gcc -Wall -Wextra -Werror -o $(NAME2) $(OBJ2) -L libft -lft \
	-I includes

$(NAME3): $(OBJ3)
	make -C libft
	gcc -Wall -Wextra -Werror -o $(NAME3) $(OBJ3) -L libft -lft \
	-I includes

%.o:%.c
	gcc -Wall -Wextra -Werror -c -o $@ $^ -I. -I includes

clean:
	make -C libft clean
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f $(OBJ3)

fclean: clean
	make -C libft fclean
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(NAME3)

re: fclean all

.PHONY: clean fclean re
