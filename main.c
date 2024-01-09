/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:27:14 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 05:27:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_shared	shared;

	shared = get_shared();
	shared->argc = argc;
	shared->argv = argv;
	validate_args();
	read_file();
	create_map_from_file();
	create_framebuffer_from_map();
	create_window_from_framebuffer();
	free_shared();
	return (0);
}
