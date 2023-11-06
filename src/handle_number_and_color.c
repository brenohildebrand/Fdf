/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:17:41 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/06 17:20:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "../kit/types/basic.h"
#include "../kit/types/vec2.h"
#include "../kit/types/vec3.h"
#include "../kit/types/rgb.h"
#include "fdf.h"
#include <stdio.h>

static void	push_point(t_map map, t_coordinates2D coordinates, t_i32 z, struct s_rgba color)
{
	push_rgba_vector(map->color, (struct s_rgba){
		.r = 0xFF,
		.g = 0xFF,
		.b = 0xFF,
		.a = 0xFF,
	});
	push_vec3_vector(map->position, (struct s_vec3){
		.x = coordinates->x,
		.y = coordinates->y,
		.z = z,
	});
}
static t_u8	hex_letter_to_number(t_u8 letter)
{
	if (letter >= '0' && letter <= '9')
		return (letter - '0');
	else if (letter >= 'a' && letter <= 'f')
		return (letter - 'a');
	else if (letter >= 'A' && letter <= 'F')
		return (letter - 'A');
	else
	{
		print((t_u8 *)"[PARSER] Hex character expected.");
		sexit(1);
	}
	return ('\0');
}

static t_i32	is_hex(t_u8 letter)
{
	if (letter >= '0' && letter <= '9')
		return (1);
	else if (letter >= 'a' && letter <= 'f')
		return (1);
	else if (letter >= 'A' && letter <= 'F')
		return (1);
	return (0);
}

static struct s_rgba	parse_color(t_file file, t_u32 *index)
{
	t_u8			current_character;
	struct s_rgba	color;
	
	if (file->buffer->data[*index + 1] != '0' || file->buffer->data[*index + 2] != 'x')
	{		
		print((t_u8 *)"[PARSER] \"0x\" was expected after ','.");
		sexit(1);	
	}
	color = (struct s_rgba){.a = 0, .r = 0, .g = 0, .b = 0};
	if (is_hex(file->buffer->data[*index + 8]))
	{
		color.r = hex_letter_to_number(file->buffer->data[*index + 3]) * 16 + 
			  hex_letter_to_number(file->buffer->data[*index + 4]) * 1;
		color.g = hex_letter_to_number(file->buffer->data[*index + 5]) * 16 + 
			  hex_letter_to_number(file->buffer->data[*index + 6]) * 1;
		color.b = hex_letter_to_number(file->buffer->data[*index + 7]) * 16 + 
			  hex_letter_to_number(file->buffer->data[*index + 8]) * 1;
		(*index) += 9;
	}
	else if (is_hex(file->buffer->data[*index + 5]))
	{
		color.g = hex_letter_to_number(file->buffer->data[*index + 3]) * 16 + 
			  hex_letter_to_number(file->buffer->data[*index + 4]) * 1;
		color.b = hex_letter_to_number(file->buffer->data[*index + 5]) * 16 + 
			  hex_letter_to_number(file->buffer->data[*index + 6]) * 1;
		(*index) += 7;
	}
	else
	{
		color.b = hex_letter_to_number(file->buffer->data[*index + 3]) * 16 + 
			  hex_letter_to_number(file->buffer->data[*index + 4]) * 1;	
		(*index) += 5;
	}
	color.a = 0xFF;
	return (color);
}

void	handle_number_and_color(
	t_file file,
	t_map map,
	t_coordinates2D coordinates,
	t_u32 *index
){
	t_i32			number;	
	t_i32			signal;
	struct s_rgba	color;
	t_u8			current_character;
	
	signal = 1;
	number = 0;
	current_character = file->buffer->data[*index];
	if (current_character == '-')
	{
		signal = -1;
		current_character = file->buffer->data[++(*index)];
	}
	if (current_character < '0' || current_character > '9')
	{
		print((t_u8 *)"[PARSER] Digit was expected, but got another character.");
		printf("%c\n", current_character);
		sexit(1);
	}
	while (current_character >= '0' && current_character <= '9')
	{
		number *= 10;
		number += current_character - '0';	
		(*index)++;
		current_character = file->buffer->data[*index];
	}
	if (current_character == ',')
		color = parse_color(file, index);
	push_point(map, coordinates, number * signal, color);
}
