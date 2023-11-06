/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:06:00 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/05 16:18:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#define PI 3.14159265358979323846

static void	rotate_x(t_point p, t_f64 angle)
{
	angle *= (PI / 180.0);
	p->position.x = p->position.x;
	p->position.y = p->position.y * cos(angle) - 
					p->position.z * sin(angle);
	p->position.z = p->position.y * sin(angle) +
					p->position.z * cos(angle);
}

static void	rotate_y(t_point p, t_f64 angle)
{
	angle *= (PI / 180.0);	
	p->position.x = p->position.x * cos(angle) +
					p->position.z * sin(angle);
	p->position.y = p->position.y;
	p->position.z = p->position.z * cos(angle) -
					p->position.x * sin(angle);
}

static void	rotate_z(t_point p, t_f64 angle)
{
	angle *= (PI / 180.0);
	p->position.x = p->position.x * cos(angle) -
					p->position.y * sin(angle);
	p->position.y = p->position.x * sin(angle) +
					p->position.y * cos(angle);
	p->position.z = p->position.z;
}

void	rotate(t_fdf fdf, t_point p)
{
	rotate_x(p, fdf->properties->rotation->x);
	rotate_y(p, fdf->properties->rotation->y);
	rotate_z(p, fdf->properties->rotation->z);
}
