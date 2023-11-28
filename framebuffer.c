/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:19:56 by marvin            #+#    #+#             */
/*   Updated: 2023/11/25 18:19:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_framebuffer	create_framebuffer(void)
{
	t_framebuffer	framebuffer;

	framebuffer = custom_malloc(sizeof(struct s_framebuffer));
	framebuffer->width = WIDTH;
	framebuffer->height = HEIGHT;
	framebuffer->length = framebuffer->width * framebuffer->height;
	framebuffer->size = framebuffer->width * framebuffer->height * sizeof(int);
	framebuffer->pixels = custom_malloc(framebuffer->size);
	return (framebuffer);
}

static void	put_line_on_framebuffer(
	t_framebuffer framebuffer,
	t_point p1,
	t_point p2
){
	double	dx;
	double	dy;
	double	x_increment;
	double	y_increment;
	int		num_steps;

	dx = p2->position->x - p1->position->x;
	dy = p2->position->y - p1->position->y;
	num_steps = (int)round(fmax(fabs(dx), fabs(dy)));
	x_increment = dx / num_steps;
	y_increment = dy / num_steps;
	while (num_steps--)
	{
		if ((int)p1->position->x + ((int)p1->position->y * framebuffer->width) \
			< framebuffer->length)
		{
			framebuffer->pixels[\
				(int)p1->position->x + \
				((int)p1->position->y * framebuffer->width) \
			] = p1->color;
		}
		p1->position->x += x_increment;
		p1->position->y += y_increment;
	}
}

// static void	init_framebuffer(t_framebuffer framebuffer, t_map map)
// {
// 	unsigned int	length;

// 	length = 0;
// 	while (length < framebuffer->length)
// 	{
// 		framebuffer->pixels[length] = 0xFFFF0000;
// 		length++;
// 	}
// put_line_on_framebuffer(framebuffer, map->address[0],
// }

static void	init_framebuffer(t_framebuffer framebuffer, t_map map)
{
	unsigned int	length;
	unsigned int	i;
	unsigned int	j;

	length = 0;
	while (length < map->length)
	{
		i = length % map->width;
		j = length / map->width;
		if (i < map->width - 1)
		{
			put_line_on_framebuffer(
				framebuffer,
				transform_one_from(map->address[length]),
				transform_two_from(map->address[length + 1]));
		}
		if (j < map->height - 1)
		{
			put_line_on_framebuffer(
				framebuffer,
				transform_one_from(map->address[length]),
				transform_two_from(map->address[length + map->width]));
		}
		length++;
	}
}

void	create_framebuffer_from_map(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->framebuffer = create_framebuffer();
	init_framebuffer(shared->framebuffer, shared->map);
}
