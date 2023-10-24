/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_file_till_the_end.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:28:04 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 18:30:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static void	realloc_file(char **file, size_t *allocated_size)
{
	size_t	i;
	char	*new_file;

	new_file = malloc(*allocated_size * 2 * sizeof(char));
	i = 0;
	while (i < *allocated_size)
	{
		new_file[i] = (*file)[i];
		i++;
	}
	free(*file);
	*allocated_size *= 2;
	*file = new_file;
}

void	read_the_file_till_the_end(int *fd, char **file)
{
	size_t	size;
	size_t	allocated_size;
	ssize_t	status;

	size = 0;
	allocated_size = 16;
	(*file) = malloc(allocated_size * sizeof(char));
	while (1)
	{
		status = read(*fd, (*file) + size, allocated_size - size);
		if (status == -1)
		{
			write(1, "An error ocurred while reading the file.\n", 41);
			free(*file);
			exit(1);
		}
		if (status == 0)
			break;
		size += status;
		if (allocated_size == size)
			realloc_file(file, &allocated_size);
	}
}
