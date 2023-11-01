/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:23:18 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/01 15:54:11 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "../kit/types/basic.h"
#include "../kit/types/vec2_vector.h"
#include "../vendor/MLX42/include/MLX42/MLX42.h"
#include <unistd.h>

#define WIDTH 256
#define HEIGHT 256

static void	bresenham_for_slope_greater_than_1(
	t_vec2_vector v, 
	t_vec2 s, 
	t_vec2 e
){
	t_i32	x;
	t_i32	y;
	t_i32	dx;
	t_i32	dy;
	t_i32	p;
	
	x = s->x;
	y = s->y;
	dx = e->x - s->x;
	dy = e->y - s->y;
	p = 2 * dx - dy;
	while(x <= e->x)
	{
		if (p < 0)
		{
			p = p + 2 * dx;
		}
		else
		{
			p = p + 2 * dx - 2 * dy;
			y++;
		}
		x++;		
	}
}

static void	bresenham_for_slope_smaller_than_1(
	t_vec2_vector v,
	t_vec2 s,
	t_vec2 e
)
{
	t_i32	x;
	t_i32	y;
	t_i32	dx;
	t_i32	dy;
	t_i32	p;
	
	x = s->x;
	y = s->y;
	dx = e->x - s->x;
	dy = e->y - s->y;
	p = 2 * dy - dx;
	while(y <= e->y)
	{
		if (p < 0)
		{
			p = p + 2 * dy;
		}
		else
		{
			p = p + 2 * dy - 2 * dx;
			x++;
		}
		y++;		
	}
}

void	bresenham(t_vec2_vector v, t_vec2 s, t_vec2 e)
{
	t_i32	dx;
	t_i32	dy;

	dx = e->x - s->x;
	dy = e->y - s->y;
	if (dy > dx)
		bresenham_for_slope_greater_than_1(v, s, e);
	else
		bresenham_for_slope_smaller_than_1(v, s, e);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Bresenham", true);
	if (!mlx)
		sexit(1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		sexit(1);
	mlx_put_pixel(img, 0, 0, 0xffffff);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	sexit(1);
}