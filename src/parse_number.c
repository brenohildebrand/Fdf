/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:42:58 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/25 11:42:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>

void	parse_number(t_llist **map, char **file, int *x, int *y)
{
	int	number;

	number = 0;
	if ((*(*file)) < '0' || (*(*file)) > '9')
	{
		write(1, "Digit was expected, but got another character.\n", 47);
		exit(1);
	}
	while ((*(*file)) >= '0' && (*(*file)) <= '9')
	{
		number *= 10;
		number += (*(*file)) - '0';
		(*file)++;
	}
	store_number_in_map(map, *x, *y, number);
}
