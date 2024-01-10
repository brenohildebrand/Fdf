/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:08:07 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 18:08:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_shared	get_shared(void)
{
	static struct s_shared	shared = {
		.file = 0,
		.map = 0,
		.framebuffer = 0,
		.window = 0
	};

	return (&shared);
}

void	free_shared(void)
{
	t_shared	shared;

	shared = get_shared();
	if (shared->file)
	{
		free(shared->file->address);
		free(shared->file);
	}
	if (shared->map)
	{
		while (shared->map->length--)
		{
			free(shared->map->address[shared->map->length]->position);
			free(shared->map->address[shared->map->length]);
		}
		free(shared->map->address);
		free(shared->map);
	}
	if (shared->framebuffer)
	{
		free(shared->framebuffer->pixels);
		free(shared->framebuffer);
	}
	if (shared->window)
		free(shared->window);
}
