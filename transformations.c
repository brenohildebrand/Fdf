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
	if (max_z != min_z)
	{
		point->position->z = (double)shared->framebuffer->height / 3.0 * \
			(double)(point->position->z - min_z) * \
			(1.0 / (double)(max_z - min_z));
	}
}#include <stdio.h>


void	scale(t_point point)
{
	t_shared	shared;

	shared = get_shared();
	point->position->x *= \
		get_scale_x() * 1.15;
	point->position->y *= \
		get_scale_y() * 1.15;
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
		get_scale_x();
	y -= shared->map->height / 2 * \
		get_scale_y();
	another_x = x * cos(-45.0 * M_PI / 180.0) - y * sin(-45.0 * M_PI / 180.0);
	another_y = (x * sin(-45.0 * M_PI / 180.0) + \
				y * cos(-45.0 * M_PI / 180.0)) * cos(54.7 * M_PI / 180.0) - \
				point->position->z * sin(54.7 * M_PI / 180.0);
	x = another_x;
	y = another_y;
	x += shared->map->width / 2 * \
		get_scale_x();
	y += shared->map->height / 2 * \
		get_scale_y();
	point->position->x = x;
	point->position->y = y;
}

void	centralize(t_point point)
{
	t_shared		shared;

	shared = get_shared();
	point->position->x += \
		fabs(get_min_x() - \
		(((double)shared->framebuffer->width / 2.0) - \
		(fabs(get_max_x() - get_min_x()) / 2.0)));
	point->position->y += \
		fabs(get_min_y() - \
		(((double)shared->framebuffer->height / 2.0) - \
		(fabs(get_max_y() - get_min_y()) / 2.0)));
}
