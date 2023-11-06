/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:06:00 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/06 15:53:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#define PI 3.14159265358979323846

static void	rotate_x(t_point p, t_f64 angle)
{
	struct s_vec3	new_position;

	angle *= (PI / 180.0);
	new_position.x = p->position.x;
	new_position.y = p->position.y * cos(angle) - 
					p->position.z * sin(angle);
	new_position.z = p->position.y * sin(angle) +
					p->position.z * cos(angle);
	p->position.x = new_position.x;
	p->position.y = new_position.y;
	p->position.z = new_position.z;
}

static void	rotate_y(t_point p, t_f64 angle)
{
	struct s_vec3	new_position;

	angle *= (PI / 180.0);	
	new_position.x = p->position.x * cos(angle) +
					p->position.z * sin(angle);
	new_position.y = p->position.y;
	new_position.z = p->position.z * cos(angle) -
					p->position.x * sin(angle);
	p->position.x = new_position.x;
	p->position.y = new_position.y;
	p->position.z = new_position.z;
}

static void	rotate_z(t_point p, t_f64 angle)
{
	struct s_vec3	new_position;

	angle *= (PI / 180.0);
	new_position.x = p->position.x * cos(angle) -
					p->position.y * sin(angle);
	new_position.y = p->position.x * sin(angle) +
					p->position.y * cos(angle);
	new_position.z = p->position.z;
	p->position.x = new_position.x;
	p->position.y = new_position.y;
	p->position.z = new_position.z;
}

void	rotate(t_fdf fdf, t_point p)
{
	rotate_x(p, fdf->properties->rotation->x);
	rotate_y(p, fdf->properties->rotation->y);
	rotate_z(p, fdf->properties->rotation->z);
}
