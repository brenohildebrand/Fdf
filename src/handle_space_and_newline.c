/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space_and_newline.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:44:10 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/06 17:21:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/types/vec2.h"
#include "../kit/actions/actions.h"

void	handle_space_and_newline(
	t_file file, 
	t_map map, 
	t_coordinates2D coordinates, 
	t_u32 *index
){
	t_u8	current_character;

	current_character = file->buffer->data[*index];
	while (current_character == ' ')
		current_character = file->buffer->data[++(*index)];
	if (current_character == '\n' || current_character == '\0')
	{
		if (map->width == 0)
		{
			map->width = coordinates->x + 1;
		}
		if (coordinates->x != map->width - 1)
		{
			print((t_u8 *)"[PARSER] Each line should have the same amount of points.");
			sexit(1);
		}
	}
	if (current_character == '\n')
	{
		(*index)++;
		while (current_character == ' ')
			current_character = file->buffer->data[++(*index)];
	}
}
