/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yet_another_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:12:35 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/30 03:58:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_max_y(void)
{
	static double	max_y;
	static int		is_calculated = 0;
	t_shared		shared;
	unsigned int	i;

	if (!is_calculated)
	{
		shared = get_shared();
		i = 0;
		max_y = shared->map->address[0]->position->y;
		while (i < shared->map->length)
		{
			if (shared->map->address[i]->position->y > max_y)
				max_y = shared->map->address[i]->position->y;
			i++;
		}
		is_calculated = 1;
	}
	return (max_y);
}

double	get_min_y(void)
{
	static double	min_y;
	static int		is_calculated = 0;
	t_shared		shared;
	unsigned int	i;

	if (!is_calculated)
	{
		shared = get_shared();
		i = 0;
		min_y = shared->map->address[0]->position->y;
		while (i < shared->map->length)
		{
			if (shared->map->address[i]->position->y < min_y)
				min_y = shared->map->address[i]->position->y;
			i++;
		}
		is_calculated = 1;
	}
	return (min_y);
}

double	get_max_x(void)
{
	static double	max_x;
	static int		is_calculated = 0;
	t_shared		shared;
	unsigned int	i;

	if (!is_calculated)
	{
		shared = get_shared();
		i = 0;
		max_x = shared->map->address[0]->position->x;
		while (i < shared->map->length)
		{
			if (shared->map->address[i]->position->x > max_x)
				max_x = shared->map->address[i]->position->x;
			i++;
		}
		is_calculated = 1;
	}
	return (max_x);
}

double	get_min_x(void)
{
	static double	min_x;
	static int		is_calculated = 0;
	t_shared		shared;
	unsigned int	i;

	if (!is_calculated)
	{
		shared = get_shared();
		i = 0;
		min_x = shared->map->address[0]->position->x;
		while (i < shared->map->length)
		{
			if (shared->map->address[i]->position->x < min_x)
				min_x = shared->map->address[i]->position->x;
			i++;
		}
		is_calculated = 1;
	}
	return (min_x);
}
