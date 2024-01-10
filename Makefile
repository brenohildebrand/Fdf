# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 05:26:41 by marvin            #+#    #+#              #
#    Updated: 2023/11/21 05:26:41 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -Ofast

SOURCES = \
	main.c \
	shared.c \
	print.c \
	args.c \
	file.c \
	map.c \
	utils.c \
	point.c \
	framebuffer.c \
	hooks.c \
	window.c \
	transform.c \
	another_utils.c \
	transformations.c \
	yet_another_utils.c

OBJECTS = \
	main.o \
	shared.o \
	print.o \
	args.o \
	file.o \
	map.o \
	utils.o \
	point.o \
	framebuffer.o \
	hooks.o \
	window.o \
	transform.o \
	another_utils.o \
	transformations.o \
	yet_another_utils.o

HEADERS = \
	fdf.h

all: norm $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

norm:
	@norminette $(SOURCES) $(HEADERS)

$(NAME): $(OBJECTS)
	@cc  -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a -lXext -lX11 -lm

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re norm