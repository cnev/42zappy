# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/07 17:29:33 by cchevall          #+#    #+#              #
#    Updated: 2014/05/25 14:15:35 by cchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC += ft_putchar_fd.c
SRC += ft_putstr_fd.c
SRC += ft_putstr_fd_sub.c
SRC += ft_putendl_fd.c
SRC += ft_puttab_fd.c
SRC += ft_putnbr_fd.c
SRC += ft_tputs_putchar.c
SRC += ft_strrchr.c
SRC += ft_isprint.c
SRC += ft_isprint_less_sp.c
SRC += ft_strlen.c
SRC += ft_tablen.c
SRC += ft_memset.c
SRC += ft_memcmp.c
SRC += ft_strcmp.c
SRC += ft_strcpy.c
SRC += ft_strcat.c
SRC += ft_strclr.c
SRC += ft_strsplit.c
SRC += ft_strdup.c
SRC += ft_strnew.c
SRC += ft_strncmp.c
SRC += ft_del_char.c
SRC += ft_strjoin.c
SRC += ft_strsub.c
SRC += ft_stradd.c
SRC += ft_memalloc.c
SRC += destroy_var.c
SRC += destroy_tab.c
SRC += get_next_line.c
SRC += ft_atoi.c
SRC += is_digit.c
SRC += ft_itoa.c
SRC += word_len.c
SRC += ft_strdel.c
SRC += ft_bzero.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc -I ../includes/

CL			= ar rc

RL			= ranlib

CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CL) $@ $^
	$(RL) $@

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

