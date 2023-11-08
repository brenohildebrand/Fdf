/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:05 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 17:58:20 by bhildebr         ###   ########.fr       */
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
	t_f64	dx;
	t_f64	dy;
	t_f64	x_increment;
	t_f64	y_increment;
	
	t_i32			index;
	struct s_vec2	delta;
	struct s_vec2	increment;
	struct s_rgba	color_increment;
	t_i32			num_steps;


	dx = p1.position.x - p0.position.x;
	dy = p1.position.y - p0.position.y;
	num_steps = (t_i32)round(fmax(fabs(dx), fabs(dy)));
	x_increment = dx / num_steps;
	y_increment = dy / num_steps;
	while (num_steps--)
	{
		color.r = p0.color.r + ((t_f64)(p1.color.r - p0.color.r) / num_steps) * 0;
		color.g = 
		put_valid_pixel(img, p0.position.x, p0.position.y, 0xFF0000FF);
		p0.position.x += x_increment;
		p0.position.y += y_increment;
	}

	delta.x = p1.position.x - p0.position.x;
	delta.y = p1.position.y - p0.position.y;
	num_steps = round(fmax(fabs(dx), fabs(dy)));
	increment.x = delta.x / num_steps;
	increment.y = delta.y / num_steps;
	color_increment.r = (p1.color.r - p0.color.r) / num_steps;
	color_increment.g = (p1.color.g - p0.color.g) / num_steps;
	color_increment.b = (p1.color.b - p0.color.b) / num_steps;
	color_increment.a = (p1.color.a - p0.color.a) / num_steps;
	index = 0;
	while (index < num_steps)
	{
		put_valid_pixel(img, p0.position.x, p0.position.y, (t_u32)
			(t_u32)p0.color.r << 24 | (t_u32)p0.color.g << 16 | p0.color.b << 8 | p0.color.a);
		p0.position.x += increment.x;
		p0.position.y += increment.y;
		p0.color.r += color_increment.r;
		p0.color.g += color_increment.g;
		p0.color.b += color_increment.b;
		p0.color.a += color_increment.a;
	}
}
