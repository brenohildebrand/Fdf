/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:40:47 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/07 03:41:27 by bhildebr         ###   ########.fr       */
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
		handle_space_and_newline(fdf->file, fdf->map, coordinates, &index);
		handle_number_and_color(fdf->file, fdf->map, coordinates, &index);
		handle_space_and_newline(fdf->file, fdf->map, coordinates, &index);
		if (fdf->map->width != 0 && coordinates->x == fdf->map->width - 1)	
		{
			coordinates->x = 0;
			coordinates->y++;
		}
		else
			coordinates->x++;
	}
	fdf->map->height = coordinates->y;
	sfree(coordinates);
}

static void	handle_number(
	t_fdf fdf, 
	t_coordinates2D coords, 
){
	t_u8	current_character;
	t_i32	signal;
	t_i32	number;
	t_i32	color;

	current_character = current_file(fdf->file);
	signal = 1;
	if (current_character == '-')
		signal = -1;
	number = 0;
	while (current_character < '0' && current_character > '9')
	{
		number *= 10;
		number += current_character - '0';
		current_character = next_file(fdf->file); 
	}
	if (current_character == ',')
	{
		while (current_character >= 'a' && current_character <= 'f' ||
				current_charater >= 'A' && current_character <= 'F' ||
				current_character >= '0' && current_character <= '9')
		{
			current_character = next_file(fdf->file);
		}
	}	
}

void	parse_file(t_fdf fdf)
{
	t_coordinates2D	coords;
	t_u8			current_character;

	init_coordinates2D(&coords);
	current_character = start_file(fdf->file);
	while (current_character != end_file(fdf->file))
	{
		while (current_character != '\n')
		{
			if (current_character != ' ')
			{
				handle_number();
				coords->x++;
			}
			current_character = next_file(fdf->file);		
		}
		if (fdf->map->width == 0)
			fdf->map->width = coords->x;
		else if (fdf->map->width != coords->x)
		{
			print("Oops! It looks like the map is not in the expected format. All the lines should contain the same amount of numbers.\n");
			sexit(1);
		}
		coords->y++;
	}
	fdf->map->height = coords->y;
	destroy_coordinates2D(&coords);	
}
