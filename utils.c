/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:20:26 by marvin            #+#    #+#             */
/*   Updated: 2023/11/25 11:20:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*custom_malloc(unsigned int size)
{
	void	*address;

	address = malloc(size);
	if (address == (void *)0)
		raise_error(255);
	return (address);
}

void	raise_error(unsigned char exit_code)
{
	print("An error ocurred.");
	exit(exit_code);
}

int	hex_to_number(unsigned char digit)
{
	if (digit >= '0' && digit <= '9')
		return (digit - '0');
	if (digit >= 'a' && digit <= 'f')
		return (digit - 'a');
	if (digit >= 'A' && digit <= 'F')
		return (digit - 'A');
	raise_error(252);
	return (0);
}

unsigned int	get_true_map_width(void)
{
	static unsigned int	true_width = 0;
	t_shared			shared;
	t_map				map;

	shared = get_shared();
	map = shared->map;
	if (true_width == 0)
		true_width = map->width;
	return (true_width);
}
