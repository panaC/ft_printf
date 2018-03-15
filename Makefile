# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 12:44:40 by pleroux           #+#    #+#              #
#    Updated: 2018/03/15 14:40:46 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc
INC_DIR =./inc

SRC_DIR = src/
SRC_FILE = format_c.c \
		   format_d.c \
		   format_s.c\
		   format_tools.c \
		   format_uox.c \
		   format_uox_attr.c \
		   ft_printf.c \
		   ft_vasprintf.c \
		   mae_parse.c \
		   param.c \
		   resolve_format.c \
		   search_next_format.c \
		   misc.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

LIB= libft/libft.a
LIB_PATH= libft/
LIB_PRINTF= libftprintf-tmp.a
NAME= libftprintf.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	ar rcs $(LIB_PRINTF) $(OBJ)
	libtool -static -o $(NAME) $(LIB_PRINTF) $(LIB)
	rm -f $(LIB_PRINTF)

$(LIB)	:
	make -C $(LIB_PATH)

clean	:
	rm -f $(OBJ)
	make -C libft/ clean

fclean	: clean
	rm -f $(NAME)
	make -C libft/ fclean

re		: clean all

.PHONY : all clean re fclean compile $(LIB)
