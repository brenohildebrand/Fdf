/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:11:45 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/06 11:59:41 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

void	ft_memset(void *mem, t_u8 byte, t_u32 size)
{
	t_u32	i;
	
	i = 0;
	while (i < size)
	{
		((t_u8 *)mem)[i] = byte;
		i++;
	}
}

void	draw_background(mlx_image_t *img)
{
	ft_memset(img->pixels, 0xFF, img->width * img->height * 4);	
}
