/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:24:17 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 16:33:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	validate_argv(char *argv[])
{
	int	last_index;

	last_index = 0;
	while (argv[1][last_index] != '\0')
		last_index++;
	if (argv[1][last_index - 1] != 'f' ||
		argv[1][last_index - 2] != 'd' ||
		argv[1][last_index - 3] != 'f' ||
		argv[1][last_index - 4] != '.')
	{
		write(1, "The file given does not end in .fdf.\n", 37);
		exit(1);
	}
}
