/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_origin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:06:50 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 13:08:35 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_to_origin(t_map map, struct s_point *p)
{
	p->position.x -= (map->width / 2) * 50;
	p->position.y += (map->width / 2) * 50;
}
