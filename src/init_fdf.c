/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:11:52 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/06 11:47:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

void	init_fdf(t_fdf *fdf)
{
	(*fdf) = smalloc(sizeof(struct s_fdf));
	(*fdf)->mlx = (mlx_t *)0;
	(*fdf)->img = (mlx_image_t *)0;
	init_file(&((*fdf)->file));
	init_map(&((*fdf)->map));
	init_properties(&((*fdf)->properties));
	init_extra(&((*fdf)->extra));
}
