/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:19:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/01/11 13:19:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print(char *message)
{
	unsigned int	size;

	size = 0;
	while (message[size] != '\0')
		size++;
	write(1, message, size);
	write(1, "\n", 1);
}
