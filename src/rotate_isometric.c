/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:04:53 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 17:55:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_isometric(t_fdf fdf, t_point p)
{
	p->position.x = (t_i32)((t_f64)p->position.x * (t_f64)cos(45.0) -
					(t_f64)p->position.y * (t_f64)sin(45.0));
	p->position.y = (t_i32)((t_f64)p->position.x * (t_f64)cos(fdf->properties->rotation->x) * (t_f64)cos(45.0) +
					(t_f64)p->position.y * (t_f64)cos(fdf->properties->rotation->x) * (t_f64)sin(45.0) -
					(t_f64)p->position.z * (t_f64)sin(fdf->properties->rotation->x));
}
