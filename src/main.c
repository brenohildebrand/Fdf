/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brenohildebrand <brenohildebrand@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:53:55 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 13:54:10 by brenohildeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	validate_args(argc, argv);
	read_the_map(&map, argv[1]);
	render_the_map(&map);
	return (0);
}
