/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:53:55 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/11 10:53:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/types/basic.h"
#include "../kit/types/file.h"
#include "../kit/actions/actions.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	init_fdf(&fdf);
	validate_args(argc, argv);
	read_file(fdf->file, (t_u8 *)argv[1]);
	parse_file(fdf);
	render_map(fdf);
	sexit(0);
}
