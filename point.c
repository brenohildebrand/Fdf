/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:19:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/01/11 13:19:31 by bhildebr         ###   ########.fr       */
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
	int	signal;

	z = 0;
	if (*(map->cursor) == '-')
	{
		signal = -1;
		(map->cursor)++;
	}
	else
		signal = 1;
	while (*(map->cursor) >= '0' && *(map->cursor) <= '9')
	{
		z *= 10;
		z += *(map->cursor) - '0';
		(map->cursor)++;
	}
	return ((double)(z * signal));
}

static int	get_color(t_map map)
{
	int	color;

	if (*(map->cursor) == ',')
	{
		(map->cursor) += 3;
		color = 0;
		color <<= 8;
		color |= 0x00;
		while ((*(map->cursor) >= '0' && *(map->cursor) <= '9') || \
				(*(map->cursor) >= 'a' && *(map->cursor) <= 'f') || \
				(*(map->cursor) >= 'A' && *(map->cursor) <= 'F'))
		{
			color <<= 8;
			color |= hex_to_number(*(map->cursor)) * 16 + \
					hex_to_number(*(map->cursor + 1)) * 1;
			(map->cursor) += 2;
		}
	}
	else
		color = (0x00 << 24) | (0xFF << 16) | (0xFF << 8) | (0xFF << 0);
	return (color);
}

static void	init_point(t_point point, t_map map)
{
	point->position->x = (double)map->width;
	point->position->y = (double)map->height - 1;
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
