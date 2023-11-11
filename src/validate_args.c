/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:19:22 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/11 10:55:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

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
		print(
			(t_u8 *)"Oops! It looks like the map is not in the expected format. \
			Make sure the file ends in .fdf.");
		sexit(1);
	}
}

void	validate_argc(int argc)
{
	if (argc != 2)
	{
		print(
			(t_u8 *)"Whew. Try running me again but in the following format: \
			./fdf <path to map>.");
		sexit(1);
	}
}

void	validate_args(int argc, char *argv[])
{
	validate_argc(argc);
	validate_argv(argv);
}
