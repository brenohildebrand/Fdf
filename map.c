/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:46:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/01/10 15:46:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	create_map(void)
{
	t_map	map;

	map = custom_malloc(sizeof(struct s_map));
	map->address = 0;
	map->size = 0;
	map->width = 0;
	map->height = 0;
	map->length = 0;
	map->cursor = 0;
	return (map);
}

static void	resize_map(t_map map)
{
	t_point			*new_address;
	unsigned int	i;

	if (map->length == 0)
	{
		map->size = 4096 * sizeof(t_point);
		map->address = custom_malloc(map->size);
		i = 4096;
		while (i--)
			map->address[i] = 0;
	}
	else
	{
		new_address = custom_malloc(map->size * 2);
		i = (map->size * 2) / sizeof(t_point);
		while (i > map->length)
			new_address[--i] = 0;
		while (i--)
			new_address[i] = map->address[i];
		free(map->address);
		map->size *= 2;
		map->address = new_address;
	}
}

static void	push_point_to_map(t_point point, t_map map)
{
	if (map->length == 0 || map->length * sizeof(t_point) > map->size / 2)
		resize_map(map);
	map->length += 1;
	map->address[map->length - 1] = point;
}

static void	init_map(t_map map, t_file file)
{
	t_point			point;

	map->cursor = (char *)file->address;
	map->height = 1;
	while (1)
	{
		while (*(map->cursor) == ' ')
			(map->cursor)++;
		if (*(map->cursor) == '\n')
		{
			if (map->width != get_true_map_width())
				raise_error(251);
			(map->cursor)++;
			if (*(map->cursor) != '\0')
				newline_update();
			while (*(map->cursor) == ' ')
				(map->cursor)++;
		}
		if (*(map->cursor) == '\0')
			break ;
		point = create_point_from_map();
		push_point_to_map(point, map);
		map->width++;
	}
}

void	create_map_from_file(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->map = create_map();
	init_map(shared->map, shared->file);
}
