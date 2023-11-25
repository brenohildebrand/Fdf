/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:19:23 by marvin            #+#    #+#             */
/*   Updated: 2023/11/25 12:19:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	create_point(void)
{
	t_point	point;

	point = custom_malloc(sizeof(struct s_point));
	point->position = custom_malloc(sizeof(struct s_position));
	point->position->x = 0;
	point->position->y = 0;
	point->position->z = 0;
	point->color = 0;
	return (point);
}

static double	get_z(t_map map)
{
	int	z;

	z = 0;
	while (*(map->cursor) >= '0' && *(map->cursor) <= '9')
	{
		z *= 10;
		z += *(map->cursor) - '0';
		(map->cursor)++;
	}
	return ((double)z);
}

static int	get_color(t_map map)
{
	int	color;

	if (*(map->cursor) == ',')
	{
		(map->cursor) += 3;
		color = 0;
		while ((*(map->cursor) >= '0' && *(map->cursor) <= '9') || \
				(*(map->cursor) >= 'a' && *(map->cursor) <= 'f') || \
				(*(map->cursor) >= 'A' && *(map->cursor) <= 'F'))
		{
			color <<= 8;
			color |= hex_to_number(*(map->cursor)) * 16 + \
					hex_to_number(*(map->cursor + 1)) * 1;
			(map->cursor) += 2;
		}
		color <<= 8;
		color |= 0xFF;
	}
	else
		color = (0x00 << 24) | (0x00 << 16) | (0x00 << 8) | (0xFF << 0);
	return (color);
}

static void	init_point(t_point point, t_map map)
{
	point->position->x = (double)map->width;
	point->position->y = (double)map->height;
	point->position->z = get_z(map);
	point->color = get_color(map);
}

t_point	create_point_from_map(void)
{
	t_shared	shared;
	t_point		point;

	shared = get_shared();
	point = create_point();
	init_point(point, shared->map);
	return (point);
}