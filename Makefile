# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 17:47:04 by bhildebr          #+#    #+#              #
#    Updated: 2023/10/12 17:47:25 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

v:						all
						@valgrind --leak-check=full --show-leak-kinds=all \
							--suppressions=./supression.sup ./fdf

v_bonus:				bonus
						@valgrind --leak-check=full --show-leak-kinds=all \
							--suppressions=./supression.sup ./fdf_bonus
