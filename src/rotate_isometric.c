/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_isometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:04:53 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/03 22:35:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_isometric(struct s_point *p)
{
	p->position.x = (t_i32)((t_f64)p->position.x * (t_f64)cos(45.0) -
					(t_f64)p->position.y * (t_f64)sin(45.0));
	p->position.y = (t_i32)((t_f64)p->position.x * (t_f64)cos(-54.7) * (t_f64)cos(45.0) +
					(t_f64)p->position.y * (t_f64)cos(-54.7) * (t_f64)sin(45.0) -
					(t_f64)p->position.z * (t_f64)sin(-54.7));
}
