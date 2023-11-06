/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:05 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/06 11:54:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../kit/actions/actions.h"
#include <unistd.h>

void	bresenham(mlx_image_t *img, struct s_point p0, struct s_point p1)
{
	t_f64	x;
	t_f64	y;
	t_f64	dx;
	t_f64	dy;
	t_f64	xIncrement;
	t_f64	yIncrement;
	t_i32	num_steps;

	dx = p1.position.x - p0.position.x;
	dy = p1.position.y - p0.position.y;
	num_steps = (t_i32)round(fmax(fabs(dx), fabs(dy)));
	xIncrement = dx / num_steps;
	yIncrement = dy / num_steps;
	x = p0.position.x;
	y = p0.position.y;
	for (int i = 0; i <= num_steps; i++)
	{
		mlx_put_pixel(img, x, y, 0xFF0000FF);
		x += xIncrement;
		y += yIncrement;
	}
}
