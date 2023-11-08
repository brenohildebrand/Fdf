/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_from_origin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:09:24 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 14:53:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_back_from_origin(t_fdf fdf, t_point p)
{
	p->position.x += (fdf->map->width / 2) * (1.0 / 3.0) * 1920.0 / (t_f64)(fdf->map->width - 1);
	p->position.y += (fdf->map->height / 2) * (1.0 / 3.0) * 1080.0 / (t_f64)(fdf->map->height - 1);
}
