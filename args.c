/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:07:55 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 22:07:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	validate_argc(int argc)
{
	if (argc != 2)
	{
		print("Usage: ./fdf <path-to-map>");
		exit(0);
	}
}

static void	ends_in_fdf(char *path_to_map)
{
	unsigned int	size;

	size = 0;
	while (path_to_map[size] != '\0')
		size++;
	if (size < 4 || \
		path_to_map[size - 4] != '.' || \
		path_to_map[size - 3] != 'f' || \
		path_to_map[size - 2] != 'd' || \
		path_to_map[size - 1] != 'f')
	{
		print("The given map should end in .fdf.");
		exit(0);
	}
}

static void	exists(char *path_to_map)
{
	int	fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
	{
		print("The given map does not exist.");
		exit(0);
	}
	close(fd);
}

static void	validate_argv(char **argv)
{
	char	*path_to_map;

	path_to_map = argv[1];
	ends_in_fdf(path_to_map);
	exists(path_to_map);
}

void	validate_args(void)
{
	t_shared	shared;

	shared = get_shared();
	validate_argc(shared->argc);
	validate_argv(shared->argv);
}
