/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:19:22 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 14:19:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		print("The given file does not end in .fdf.");
		exit(1);
	}
}

void	validate_argc(int argc)
{
	if (argc != 2)
	{
		print("Invalid number of arguments.");
		exit(1);
	}
}

void	validate_args(int argc, char *argv[])
{
	validate_argc(argc);
	validate_argv(argv);
}
