/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_number_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:50:07 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/25 11:52:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	store_number_in_map(t_llist **map, int x, int y, int z)
{
	static t_llist	**next = NULL;
	t_llist			*current;

	current = malloc(sizeof(t_llist));
	if (current == NULL)
	{
		// free map, free file
		exit(1);
	}
	current->point.x = x;
	current->point.y = y;
	current->point.z = z;
	if (next == NULL)
		next = map;
	(*next) = current;
	next = &(current->next);	
}
