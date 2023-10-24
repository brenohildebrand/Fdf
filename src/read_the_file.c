/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:19:31 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 18:21:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_the_file(char **file, char *path)
{
	int	fd;

	open_the_file(&fd, path);
	read_the_file_till_the_end(&fd, file);
	close_the_file(&fd);
}
