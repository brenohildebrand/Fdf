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
	file.c

OBJECTS = \
	main.o \
	shared.o \
	print.o \
	args.o \
	file.o

all: norm $(NAME)

norm:
	@norminette $(SOURCES)

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