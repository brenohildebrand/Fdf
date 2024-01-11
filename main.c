/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:19:23 by bhildebr          #+#    #+#             */
/*   Updated: 2024/01/11 13:19:23 by bhildebr         ###   ########.fr       */
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
