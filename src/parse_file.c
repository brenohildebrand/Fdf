/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:40:47 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 20:59:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "../kit/types/basic.h"
#include "../kit/types/vec2.h"
#include "fdf.h"

void	parse_file(t_fdf fdf)
{
	t_u32			index;
	t_coordinates2D	coordinates;
	
	index = 0;
	coordinates = smalloc(sizeof(struct s_coordinates2D));
	(*coordinates) = (struct s_coordinates2D){.x = 0, .y = 0};
	while (fdf->file->buffer->data[index])
	{
		handle_number_and_color(fdf->file, fdf->map, coordinates, &index);
		handle_space_or_newline(fdf->file, fdf->map, coordinates, &index);
		if (fdf->map->width != 0 && coordinates->x == fdf->map->width - 1)	
		{
			coordinates->x = 0;
			coordinates->y++;
		}
		else
			coordinates->x++;
	}
	fdf->map->height = coordinates->y;
}

