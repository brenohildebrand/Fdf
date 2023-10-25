/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_the_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:14:37 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/25 00:39:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');	
}

static int	get_line_size(char *file)
{
	int	line_size;
	
	line_size = 0;
	while (file[line_size] != '\n' && file[line_size] != '\0')
		line_size++;
	return (line_size);
}

void	parse_the_file(t_llist **map, char *file)
{
	int	x;
	int	y;
	int	line_size;

	x = 0;
	y = 0;
	line_size = get_line_size(file);
	while(*file)
	{
		parse_number(map, &file, &x, &y);
		parse_space_or_newline(&file, &x, &y, line_size);
	}
}

























/*
size_t	i;
	int		line_size;
	int		x;
	int		y;
	int		number;

	i = 0;
	line_size = get_line_size(file);
	x = 0;
	y = 0;
	while (file[i])
	{
		if (!is_digit(file[i]))
		{
			printf("Digit expected, but character '%c' found.\n", file[i]);
			// free_map();
			free(file);
			exit(1);
		}
		while (is_digit(file[i]))
		{
			number *= 10;
			number += (int)(file[i] - '0');
			i++;
		}
		(*map) = malloc(sizeof(t_llist));
		if ((*map) == 0)
			exit(1);
		(*map)->point = (t_vec3){.x = x, .y = y, .z = number};
		(*map)->next = malloc(sizeof(t_llist));
		(*map) = (*map)->next;
		x++;
		if (file[i] == '\n')
		{
			if (point.x != line_size)
			{
				printf("Each line should have the same number of points.\n");
				// free_map();
				free(file);
				exit(1);
			}
			y++;
			continue;
		}
		if (file[i] != ' ')
		{
			write(1, "Space was expected, but found another character.\n", 49);
			exit(1);
		}
		while (file[i] == ' ')
			i++;
	}
	free((*map)->next);
	(*map)->next = NULL;
*/
