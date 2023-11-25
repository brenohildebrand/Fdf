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

	file = malloc(sizeof(struct s_file));
	if (file == (void *)0)
	{
		print("An error ocurred.");
		exit(255);
	}
	file->address = 0;
	file->size = 0;
	return (file);
}

static void	resize_file(t_file file)
{
	void			*new_address;
	unsigned int	size;

	if (file->size == 0)
	{
		file->size = 4096;
		file->address = malloc(file->size * sizeof(unsigned char));
	}
	else
	{
		new_address = malloc(file->size * 2 * sizeof(unsigned char));
		size = file->size;
		while (size--)
			((unsigned char *)(new_address))[size] = \
				((unsigned char *)(file->address))[size];
		size = file->size * 2;
		while (--size >= file->size)
			((unsigned char *)(new_address))[size] = 0;
		free(file->address);
		file->size = file->size * 2;
		file->address = new_address;
	}
}

static void	init_file(t_file file, char *path)
{
	int				fd;
	unsigned int	nread;
	unsigned int	previous_file_size;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print("An error ocurred.");
		exit(254);
	}
	previous_file_size = file->size;
	while (1)
	{
		resize_file(file);
		nread = read(fd, file->address, file->size - previous_file_size);
		if (nread == 0)
			break ;
		if (nread == -1)
		{
			print("An error ocurred.");
			exit(253);
		}
		previous_file_size = file->size;
	}
	close(fd);
}

void	read_file(void)
{
	t_shared	shared;
	t_file		file;

	shared = get_shared();
	file = create_file();
	init_file(file, shared->argv[1]);
}
