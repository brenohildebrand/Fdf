/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space_or_newline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:36:28 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/25 11:43:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	parse_space_or_newline(char **file, int *x, int *y, int line_size)
{
	if ((*(*file)) == '\n')
	{
		if (*x != line_size)
		{
			write(1, "Each line should have the same size.\n", 37);		
			exit(1);
		}
		(*y)++;
	}
	else if ((*(*file)) != ' ')
	{
		write(1, "A space was expected, but got another character.\n", 49);
		exit(1);
	}
	(*file)++;
}
