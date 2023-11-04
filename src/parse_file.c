/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:40:47 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 15:41:51 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "../kit/types/basic.h"
#include "../kit/types/vec2.h"
#include "fdf.h"

void	parse_file(t_file file, t_map map)
{
	t_u32	index;
	t_vec2	coordinates;
	
	index = 0;
	init_vec2(&coordinates);
	while (file->buffer->data[index])
	{
		handle_number_and_color(file, map, coordinates, &index);
		handle_space_or_newline(file, map, coordinates, &index);
		if (map->width != 0 && coordinates->x == map->width - 1)	
		{
			coordinates->x = 0;
			coordinates->y++;
		}
		else
			coordinates->x++;
	}
	map->height = coordinates->y;
}

