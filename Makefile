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
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	main.c \
	shared.c \
	print.c

OBJECTS = \
	main.o \
	shared.o \
	print.o

all: $(NAME)

run: $(NAME)
	@./$(NAME)

$(NAME): $(OBJECTS)
	@cc  -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a -lXext -lX11

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
shared.o: shared.c
print.o: print.c