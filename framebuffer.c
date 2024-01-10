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
	unsigned int	i;

	framebuffer = custom_malloc(sizeof(struct s_framebuffer));
	framebuffer->width = WIDTH;
	framebuffer->height = HEIGHT;
	framebuffer->length = framebuffer->width * framebuffer->height;
	framebuffer->size = framebuffer->width * framebuffer->height * sizeof(int);
	framebuffer->pixels = custom_malloc(framebuffer->size);
	i = framebuffer->length;
	while (i--)
		framebuffer->pixels[i] = 0;
	return (framebuffer);
}

static void	put_line_on_framebuffer(
	t_framebuffer framebuffer,
	t_point p1,
	t_point p2
){
	struct s_position	delta;
	struct s_position	increment;
	struct s_position	point;
	int					num_steps;

	point.x = p1->position->x;
	point.y = p1->position->y;
	delta.x = p2->position->x - p1->position->x;
	delta.y = p2->position->y - p1->position->y;
	num_steps = (int)round(fmax(fabs(delta.x), fabs(delta.y)));
	increment.x = delta.x / num_steps;
	increment.y = delta.y / num_steps;
	while (num_steps--)
	{
		if ((int)point.x + ((int)point.y * framebuffer->width) \
			< framebuffer->length)
		{
			framebuffer->pixels[\
				(int)point.x + \
				((int)point.y * framebuffer->width) \
			] = p1->color;
		}
		point.x += increment.x;
		point.y += increment.y;
	}
}

static void	init_framebuffer(t_framebuffer framebuffer, t_map map)
{
	unsigned int	length;
	unsigned int	i;
	unsigned int	j;

	transform();
	length = 0;
	while (length < map->length)
	{
		i = length % map->width;
		j = length / map->width;
		if (i < map->width - 1)
		{
			put_line_on_framebuffer(framebuffer,
				map->address[length], map->address[length + 1]);
		}
		if (j < map->height - 1)
		{
			put_line_on_framebuffer(framebuffer,
				map->address[length], map->address[length + map->width]);
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
