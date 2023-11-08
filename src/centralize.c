/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centralize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:11:53 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 15:52:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centralize(t_fdf fdf, t_point p)
{
	p->position.x += (1920 - (fdf->map->width * fdf->properties->scale->x)) / 2;
	p->position.y += (1080 - (fdf->map->height * fdf->properties->scale->y)) / 2;
}
