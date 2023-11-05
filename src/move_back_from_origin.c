/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_from_origin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:09:24 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 17:45:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_back_from_origin(t_fdf fdf, t_point p)
{
	p->position.x += (fdf->map->width / 2) * 50;
	p->position.y += (fdf->map->height / 2) * 50;
}
