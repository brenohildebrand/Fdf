/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:00:01 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/03 14:23:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/types/vec3.h"
#include "../kit/actions/actions.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

static void	drawline_for_slope_greater_than_one(
	mlx_image_t	*img, 
	struct s_point p0, 
	struct s_point p1
){
	t_f64	a;
	t_f64	actual_x;
	t_u32	x;
	t_u32	y;

	a = (t_f64)(p1.position.x - p0.position.x) /
		(t_f64)(p1.position.y - p0.position.y);
	x = p0.position.x;
	actual_x = (t_f64)x;
	y = p0.position.y;
	while (y <= p1.position.y)
	{
		mlx_put_pixel(img, x, y, 0xFF0000FF);
		actual_x += a;
		x = (t_i32)actual_x;
		y++;
	}
}

static void	drawline_for_slope_smaller_than_one(
	mlx_image_t	*img,
	struct s_point p0,
	struct s_point p1
){
	t_f64	a;
	t_u32	b;
	t_u32	x;
	t_u32	y;

	a = (t_f64)(p1.position.y - p0.position.y) /
		(t_f64)(p1.position.x - p0.position.x);
	b = p0.position.y - a * p0.position.x;
	x = p0.position.x;
	y = p0.position.y;
	while (x <= p1.position.x)
	{
		mlx_put_pixel(img, x, y, 0xFF0000FF);
		x++;
		y = a * x + b;
	}
}

void	drawline(mlx_image_t *img, struct s_point p0, struct s_point p1)
{
	t_f64	slope;

	slope = (t_f64)(p1.position.y - p0.position.y) / (t_f64)(p1.position.x - p0.position.x);
	if (slope > 1.0)
		drawline_for_slope_greater_than_one(img, p0, p1);
	else
		drawline_for_slope_smaller_than_one(img, p0, p1);
}
