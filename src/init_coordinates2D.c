/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinates2D.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:55:18 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 09:56:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

void	init_coordinates2D(t_coordinates2D *coords)
{
	(*coords) = smalloc(sizeof(struct s_coordinates2D));
	(*coords)->x = 0;
	(*coords)->y = 0;	
}
