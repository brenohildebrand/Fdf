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

	shared = get_shared();
	x = point->position->x;
	y = point->position->y;
	x -= shared->map->width / 2 * \
		shared->framebuffer->width / (3 * (shared->map->width - 1));
	y -= shared->map->height / 2 * \
		shared->framebuffer->height / (3 * (shared->map->height - 1));
	x = x + cos(120.0 * 3.14159265 / 180.0) * point->position->z;
	y = y + sin(120.0 * 3.14159265 / 180.0) * point->position->z;
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
