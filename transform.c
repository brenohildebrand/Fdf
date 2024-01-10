/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:32:24 by marvin            #+#    #+#             */
/*   Updated: 2023/11/26 18:32:24 by marvin           ###   ########.fr       */
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
