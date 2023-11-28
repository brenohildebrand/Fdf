/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:35:59 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 13:35:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	newline_update(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->map->height++;
	shared->map->width = 0;
}
