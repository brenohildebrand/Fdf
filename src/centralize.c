/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centralize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:11:53 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 17:49:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centralize(t_fdf fdf, t_point p)
{
	p->position.x += (1920 - (fdf->map->width * 50)) / 2;
	p->position.y += (1080 - (fdf->map->height * 50)) / 2;
	p->position.y += (1080 / 7);
}
