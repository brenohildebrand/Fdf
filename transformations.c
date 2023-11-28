/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:32:32 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 19:32:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalize_z(t_point point)
{
	t_shared	shared;
	double		max_z;
	double		min_z;

	shared = get_shared();
	max_z = get_max_z();
	min_z = get_min_z();
	point->position->z = (double)shared->framebuffer->height / 3.0 * \
		(double)(point->position->z - min_z) * (1.0 / (double)(max_z - min_z));
}

void	scale(t_point point)
{
	t_shared	shared;

	shared = get_shared();
	point->position->x *= \
		shared->framebuffer->width / (3 * (shared->map->width - 1));
	point->position->y *= \
		shared->framebuffer->height / (3 * (shared->map->height - 1));
}

void	isometrify(t_point point)
{
	t_shared	shared;
	double		x;
	double		y;
	double		another_x;
	double		another_y;

	shared = get_shared();
	x = point->position->x;
	y = point->position->y;
	x -= shared->map->width / 2 * \
		shared->framebuffer->width / (3 * (shared->map->width - 1));
	y -= shared->map->height / 2 * \
		shared->framebuffer->height / (3 * (shared->map->height - 1));
	another_x = x * cos(-45 * M_PI / 180.0) - y * sin(-45 * M_PI / 180.0);
	another_y = (x * sin(-45 * M_PI / 180.0) + \
				y * cos(-45 * M_PI / 180.0)) * cos(54.7 * M_PI / 180.0) - \
				point->position->z * sin(54.7 * M_PI / 180.0);
	x = another_x;
	y = another_y;
	x += shared->map->width / 2 * \
		shared->framebuffer->width / (3 * (shared->map->width - 1));
	y += shared->map->height / 2 * \
		shared->framebuffer->height / (3 * (shared->map->height - 1));
	point->position->x = x;
	point->position->y = y;
}

void	centralize(t_point point)
{
	t_shared		shared;

	shared = get_shared();
	point->position->x += \
		(shared->framebuffer->width - (shared->map->width * \
		(shared->framebuffer->width / (3 * (shared->map->width - 1))) \
		)) / 2;
	point->position->y += \
		(shared->framebuffer->height - (shared->map->height * \
		(shared->framebuffer->height / (3 * (shared->map->height - 1))) \
		)) / 2;
}
