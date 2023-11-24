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

SOURCES = \
	main.c \
	shared.c \

all: $(NAME)

$(NAME): $(OBJECTS)
	cc  -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a -lXext -lX11

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re