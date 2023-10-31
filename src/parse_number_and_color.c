/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number_and_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:17:41 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/31 00:30:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "../kit/types/basic.h"
#include "../kit/types/vec2.h"
#include "../kit/types/vec3.h"
#include "../kit/types/rgb.h"
#include "fdf.h"

static void	push_point(t_map map, t_vec2 coordinates, t_i32 z, struct s_rgba color)
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

static struct s_rgba	parse_color(t_file file, t_u32 *index)
{
	t_u8			current_character;	
	struct s_rgba	color;
	
	// TODO: parse color in the format 0xffffff or 0xFFFFFF
	print("TODO: parse colors.");
	sexit(1);
	
	return (color);
}

void	parse_number_and_color(
	t_file file,
	t_map map,
	t_vec2 coordinates,
	t_u32 *index
){
	t_i32			number;	
	struct s_rgba	color;
	t_u8			current_character;
	
	number = 0;
	current_character = file->buffer->data[*index];
	if (current_character < '0' || current_character > '9')
	{
		print("[PARSER] Digit was expected, but got another character.");
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
	push_point(map, coordinates, number, color);
}
