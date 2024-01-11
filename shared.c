/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:19:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/01/11 13:19:44 by bhildebr         ###   ########.fr       */
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
