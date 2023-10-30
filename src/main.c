/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:53:55 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/30 04:42:10 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/types/file.h"
#include "../kit/actions/actions.h"
#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_file	file;
	t_llist	*map;
	
	validate_args(argc, argv);
	read_file(file, argv[1]);
	print(file->buffer->data);
	// read_the_file(&file, argv[1]);
	// parse_the_file(&map, file);
	// render_the_map(); 
	// printf("%s\n", file);
	return(0);
}
