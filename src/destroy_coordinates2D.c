/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_coordinates2D.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:57:42 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 09:58:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

void	destroy_coordinates2D(t_coordinates2D *coords)
{
	sfree(*coords);
	*coords = 0;
}
