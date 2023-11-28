/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:32:24 by marvin            #+#    #+#             */
/*   Updated: 2023/11/26 18:32:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform(t_point point)
{
	scale(point);
	isometrify(point);
	centralize(point);
}
// normalize z
// scale
// rotate
// centralize

t_point	transform_one_from(t_point point)
{
	static struct s_position	current_s_position;
	static struct s_point		current_s_point = (struct s_point){
		.position = &current_s_position
	};
	static t_point				current_point = &current_s_point;

	current_point->position->x = point->position->x;
	current_point->position->y = point->position->y;
	current_point->position->z = point->position->z;
	current_point->color = point->color;
	transform(current_point);
	return (current_point);
}

t_point	transform_two_from(t_point point)
{
	static struct s_position	current_s_position;
	static struct s_point		current_s_point = (struct s_point){
		.position = &current_s_position
	};
	static t_point				current_point = &current_s_point;

	current_point->position->x = point->position->x;
	current_point->position->y = point->position->y;
	current_point->position->z = point->position->z;
	current_point->color = point->color;
	transform(current_point);
	return (current_point);
}
