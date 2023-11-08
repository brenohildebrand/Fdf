/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:01:04 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 15:50:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	scale(t_fdf fdf, t_point p)
{
	p->position.x *= fdf->properties->scale->x;
	p->position.y *= fdf->properties->scale->y;
}
