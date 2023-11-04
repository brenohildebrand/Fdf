/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space_or_newline.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:44:10 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 15:42:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/types/vec2.h"
#include "../kit/actions/actions.h"

void	handle_space_or_newline(
	t_file file, 
	t_map map, 
	t_vec2 coordinates, 
	t_u32 *index
){
	t_u8	current_character;

	current_character = file->buffer->data[*index];
	while (current_character == ' ')
	{
		(*index)++;
		current_character = file->buffer->data[*index];
	}
	if (current_character == '\n' || current_character == '\0')
	{
		if (map->width == 0)
		{
			map->width = coordinates->x + 1;
		}
		if (coordinates->x != map->width - 1)
		{
			print("[PARSER] Each line should have the same amount of points.");
			sexit(1);
		}
		if (current_character == '\n')
			(*index)++;
	}
}
