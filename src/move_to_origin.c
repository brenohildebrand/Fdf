/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_origin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:06:50 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 15:51:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_to_origin(t_fdf fdf, t_point p)
{
	p->position.x -= (fdf->map->width / 2) * fdf->properties->scale->x;
	p->position.y -= (fdf->map->height / 2) * fdf->properties->scale->y;
}
