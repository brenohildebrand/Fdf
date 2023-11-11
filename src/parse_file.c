/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:40:47 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/11 10:57:49 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "../kit/types/basic.h"
#include "../kit/types/vec2.h"
#include "fdf.h"

static t_i32	hex_to_number(t_u8 current_character)
{
	if (current_character >= 'a' && current_character <= 'f')
		return ((current_character - 'a') + 10);
	else if (current_character >= 'A' && current_character <= 'F')
		return ((current_character - 'A') + 10);
	else if (current_character >= '0' && current_character <= '9')
		return (current_character - '0');
	else
	{
		print(
			(t_u8 *)"Oops! It looks like the map is not in the expected format. \
			Make sure the hex color codes are valid.");
		sexit(1);
	}
	return (0);
}

static void	next_color_update(t_fdf fdf)
{
	t_u8	current_character;
	t_u8	next_character;
	t_i32	color;
	t_i32	count;

	color = 0;
	current_character = current_file();
	if (current_character == ',')
	{
		current_character = next_file();
		next_character = next_file();
		count = 0;
		current_character = next_file();
		while (current_character != ' ' && current_character != '\n' && current_character != '\0')
		{
			next_character = next_file();
			color <<= 8;
			color |= (hex_to_number(current_character) * 16 + hex_to_number(next_character) * 1);
			count++;
			current_character = next_file();
		}
		color <<= 8;
		color |= 0xFF;
	}
	else
	{
		color <<= 8;
		color |= 0x00;
		color <<= 8;
		color |= 0x00;
		color <<= 8;
		color |= 0x00;
		color <<= 8;
		color |= 0xFF;
	}
	push_rgba_vector(fdf->map->color, (struct s_rgba){
		.r = (color >> 24 & 0xFF), .g = (color >> 16 & 0xFF),
		.b = (color >> 8 & 0xFF), .a = (color >> 0 & 0xFF)});
}

static void	next_number_update(
	t_fdf fdf,
	t_coordinates2d coords
){
	t_u8	current_character;
	t_i32	signal;
	t_i32	number;

	current_character = current_file();
	signal = 1;
	if (current_character == '-')
	{
		signal = -1;
		current_character = next_file();
	}
	number = 0;
	while (current_character >= '0' && current_character <= '9')
	{
		number *= 10;
		number += current_character - '0';
		current_character = next_file();
	}
	number *= signal;
	push_vec3_vector(fdf->map->position, (struct s_vec3){
		.x = coords->x, .y = coords->y, .z = number
	});
	coords->x++;
}

static void	end_line_update(t_fdf fdf, t_coordinates2d coords)
{
	if (fdf->map->width == 0)
	{
		fdf->map->width = coords->x;
	}
	else if (fdf->map->width != coords->x)
	{
		print(
			(t_u8 *)"Oops! It looks like the map is not in the expected format. \
			Make sure all the lines contain the same amount of numbers.");
		sexit(1);
	}
	coords->y++;
	coords->x = 0;
}

void	parse_file(t_fdf fdf)
{
	t_coordinates2d	coords;
	t_u8			current_character;

	init_coordinates2d(&coords);
	current_character = start_file(fdf->file);
	while (!done_file())
	{
		while (current_character != '\n' && current_character != '\0')
		{
			if (current_character != ' ')
			{
				next_number_update(fdf, coords);
				next_color_update(fdf);
				current_character = current_file();
			}
			else
				current_character = next_file();
		}
		end_line_update(fdf, coords);
		current_character = next_file();
	}
	fdf->map->height = coords->y;
	destroy_coordinates2d(&coords);
}
