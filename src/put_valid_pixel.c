/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_valid_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:28:51 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/06 16:31:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_valid_pixel(mlx_image_t *img, t_f64 x, t_f64 y, t_u32 color)
{
	if (x >= 0 && x <= img->width && y >= 0 && y <= img->height)
		mlx_put_pixel(img, x, y, color);
}