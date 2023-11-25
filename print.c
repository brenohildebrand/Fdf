/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:16:51 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 18:16:51 by marvin           ###   ########.fr       */
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