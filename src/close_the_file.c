/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_the_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:24:59 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 18:18:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	close_the_file(int *fd)
{
	if (close(*fd) == -1)
	{
		write(1, "Couldn't close the file.\n", 25);
		exit(1);
	}
}
