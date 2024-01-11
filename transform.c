/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:19:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/01/11 13:19:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform(void)
{
	t_shared		shared;
	unsigned int	i;

	shared = get_shared();
	i = 0;
	while (i < shared->map->length)
		normalize_z(shared->map->address[i++]);
	i = 0;
	while (i < shared->map->length)
		scale(shared->map->address[i++]);
	i = 0;
	while (i < shared->map->length)
		isometrify(shared->map->address[i++]);
	i = 0;
	while (i < shared->map->length)
		centralize(shared->map->address[i++]);
}
