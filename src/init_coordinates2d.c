/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinates2D.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:55:18 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/11 10:54:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

void	init_coordinates2d(t_coordinates2d *coords)
{
	(*coords) = smalloc(sizeof(struct s_coordinates2d));
	(*coords)->x = 0;
	(*coords)->y = 0;	
}
