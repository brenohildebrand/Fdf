/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:53:55 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/31 00:13:31 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/types/basic.h"
#include "../kit/types/file.h"
#include "../kit/actions/actions.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

t_u8	main(int argc, char *argv[])
{
	t_file	file;
	t_map	map;

	validate_args(argc, argv);
	init_file(&file);
	read_file(file, argv[1]);
	init_map(&map);
	parse_file(file, map);
	// destroy_file();
	render_map(map);

	return(0);
}
