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
	framebuffer->size = framebuffer->width * framebuffer->height * sizeof(int);
	framebuffer->pixels = custom_malloc(framebuffer->size);
	return (framebuffer);
}

static void	init_framebuffer(t_framebuffer framebuffer, t_map map)
{
	t_point			point;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	framebuffer->length = 0;
	while (framebuffer->length < map->length)
	{
		point = map->address[length];
		i = point->position->x;
		j = point->position->y;
		k = point->position->z;
		k += 1;
		framebuffer->pixels[i + (j * map->width)] = point->color;
		(framebuffer->length)++;
	}
}
// scale
// rotate
// do whatever on i, j and k
// i += (1.0 / 3.0) * framebuffer->width / map->width;
// j += (1.0 / 3.0) * framebuffer->height / map->height;

void	create_framebuffer_from_map(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->framebuffer = create_framebuffer();
	init_framebuffer(shared->framebuffer, shared->map);
}
