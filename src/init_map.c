/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:29:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/30 19:08:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "fdf.h"

void	init_map(t_map *map)
{
	(*map) = smalloc(sizeof(struct s_map));
	init_rgba_vector(&(*map)->color);
	init_vec3_vector(&(*map)->position);
	(*map)->height = 0;
	(*map)->width = 0;
}
