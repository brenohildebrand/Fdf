# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 17:47:04 by bhildebr          #+#    #+#              #
#    Updated: 2023/10/24 16:30:46 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all: 
	cc -Wall -Wextra -Werror src/*.c -o $(NAME)

valgrind:	all
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=./supression.sup ./fdf

valgrind_bonus:	bonus
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=./supression.sup ./fdf_bonus

.PHONY: $(NAME) all
