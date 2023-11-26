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
CFLAGS = -Wall -Wextra -Werror -g

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
	window.c

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
	window.o

HEADERS = \
	fdf.h

all: norm $(NAME)

norm:
	@norminette $(SOURCES) $(HEADERS)

$(NAME): $(OBJECTS)
	@cc  -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a -lXext -lX11

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re norm

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
shared.o: shared.c
print.o: print.c
args.o: args.c
file.o: file.c
map.o: map.c
utils.o: utils.c
point.o: point.c