# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 17:47:04 by bhildebr          #+#    #+#              #
#    Updated: 2023/11/08 16:35:25 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

$(NAME): all

all:
	cc -Wall -Wextra -Werror src/*.c kit/actions/*.c vendor/MLX42/build/libmlx42.a -o $(NAME) -ldl -lpthread -lglfw -lm -g -Ivendor/MLX42/include

valgrind:	all
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=./supression.sup ./fdf

valgrind_bonus:	bonus
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=./supression.sup ./fdf_bonus

.PHONY: $(NAME) all
