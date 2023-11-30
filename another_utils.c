/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:35:59 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 13:35:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	newline_update(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->map->height++;
	shared->map->width = 0;
}

double	get_max_z(void)
{
	static double	max_z = 0.0;
	static int		is_calculated = 0;
	unsigned int	i;
	t_shared		shared;

	if (!is_calculated)
	{
		shared = get_shared();
		i = 0;
		max_z = shared->map->address[0]->position->z;
		while (i < shared->map->length)
		{
			max_z = fmax(max_z, shared->map->address[i]->position->z);
			i++;
		}
		is_calculated = 1;
	}
	return (max_z);
}

double	get_min_z(void)
{
	static double	min_z = 0.0;
	static int		is_calculated = 0;
	unsigned int	i;
	t_shared		shared;

	if (!is_calculated)
	{
		shared = get_shared();
		i = 0;
		min_z = shared->map->address[0]->position->z;
		while (i < shared->map->length)
		{
			min_z = fmin(min_z, shared->map->address[i]->position->z);
			i++;
		}
		is_calculated = 1;
	}
	return (min_z);
}

double	get_scale_x(void)
{
	static double	scale_x = 0;
	t_shared		shared;

	shared = get_shared();
	if (scale_x == 0)
		scale_x = \
			(double)shared->framebuffer->width / \
			(double)(3 * (shared->map->width - 1));
	return (scale_x);
}

double	get_scale_y(void)
{
	return (get_scale_x());
}
// static double	scale_y = 0;
// t_shared		shared;

// shared = get_shared();
// if (scale_y == 0)
// return (scale_y);
