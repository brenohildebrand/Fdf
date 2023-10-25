/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_number_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:50:07 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/25 00:54:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_number_in_map(t_llist **map, int x, int y, int z)
{
	(*map) = malloc(sizeof(t_llist));
	(*map)->point.x = x;
	(*map)->point.y = y;
	(*map)->point.z = z;
	
	// map now should be the next ...
	// bug

	return(0);
}
