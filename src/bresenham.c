/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:05 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 17:49:54 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	bresenham(mlx_image_t *img, struct s_point p0, struct s_point p1)
{
	t_i32	dx;
	t_i32	dy;
	t_i32	sx;
	t_i32	sy;
	t_i32	err;
	t_i32	e2;

	// printf(
		// "From (%d, %d) to (%d, %d)\n",
		// p0.position.x, p0.position.y,
		// p1.position.x, p1.position.y);
	dx = abs(p1.position.x - p0.position.x);
	dy = - abs(p1.position.y - p0.position.y);	
	if (p0.position.x < p1.position.x)
		sx = 1;
	else
		sx = -1;
	if (p0.position.y < p1.position.y)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	while (1)
	{
		// printf("Pixel at (%d, %d)\n", p0.position.x, p0.position.y);
		mlx_put_pixel(img, abs(p0.position.x), abs(p0.position.y), 0xFF0000FF);
		if (p0.position.x == p1.position.x && p0.position.y == p1.position.y)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			p0.position.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			p0.position.y += sy;
		}
	}
}
