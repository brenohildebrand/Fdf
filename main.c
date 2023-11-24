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

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print("Usage: ./fdf <path-to-map>\n");
		exit(0);
	}

	// test if the path ends in .fdf
	// test if you can open it

	return (0);
}