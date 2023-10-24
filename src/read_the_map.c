/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brenohildebrand <brenohildebrand@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:59:48 by brenohildeb       #+#    #+#             */
/*   Updated: 2023/10/24 13:52:42 by brenohildeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_the_map(t_map *map, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1) 
	{
		// free map
		exit(1);
	}
	read_the_file();
	if (close(fd) == -1)
	{
		exit(1);	
	}
	check_the_file();
}
