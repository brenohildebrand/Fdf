/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:40:56 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 22:40:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_file	create_file(void)
{
	t_file	file;

	file = custom_malloc(sizeof(struct s_file));
	file->address = 0;
	file->size = 0;
	return (file);
}

static void	resize_file(t_file file)
{
	unsigned char	*new_address;
	unsigned int	size;

	if (file->size == 0)
	{
		file->size = 4096 * sizeof(unsigned char);
		file->address = custom_malloc(file->size);
	}
	else
	{
		new_address = custom_malloc(file->size * 2 * sizeof(unsigned char));
		size = file->size;
		while (size--)
			new_address[size] = file->address[size];
		size = file->size * 2;
		while (--size >= file->size)
			new_address[size] = 0;
		free(file->address);
		file->size = file->size * 2;
		file->address = new_address;
	}
}

static void	init_file(t_file file, char *path)
{
	int				fd;
	ssize_t			nread;
	unsigned int	size;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		raise_error(254);
	size = file->size;
	while (1)
	{
		resize_file(file);
		nread = read(fd, file->address + size, file->size - size);
		if (nread == 0)
			break ;
		if (nread == -1)
			raise_error(253);
		size = file->size;
	}
	close(fd);
}

void	read_file(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->file = create_file();
	init_file(shared->file, shared->argv[1]);
}
