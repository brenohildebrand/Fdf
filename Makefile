# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 17:47:04 by bhildebr          #+#    #+#              #
#    Updated: 2023/10/12 17:57:13 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

valgrind:	all
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=./supression.sup ./fdf

valgrind_bonus:	bonus
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=./supression.sup ./fdf_bonus
