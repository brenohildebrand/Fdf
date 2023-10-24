/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_the_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:22:12 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 18:26:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	open_the_file(int *fd, char *path)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		perror("Oh no!");
		write(1, "Couldn't open the file.\n", 24);
		exit(1);
	}
}
