/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:05:23 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/02 15:13:53 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/types/vec2.h"
#include "../kit/actions/actions.h"
#include "../vendor/MLX42/include/MLX42/MLX42.h"

#define WIDTH 1280
#define HEIGHT 720

static void	drawline(mlx_t *mlx, struct s_vec2 p0, struct s_vec2 p1)
{
	mlx_image_t	*img;
	t_f64		a;
	t_u32		b;
	t_u32		x;
	t_u32		y;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || mlx_image_to_window(mlx, img, 0, 0) < 0)
		sexit(1);
	a = (t_f64)(p1.y - p0.y) / (t_f64)(p1.x - p0.x);
	b = p0.y - a * p0.x;
	x = p0.x;
	y = p0.y;
	if (a > 1.0)
		while (y <= p1.y)
		{
			x = (t_f64)(y - b) / a;	
			mlx_put_pixel(img, x, y, 0xFF0000FF);
			y++;
		}
	else
	{
		while (x <= p1.x)
		{
			y = a * x + b;	
			mlx_put_pixel(img, x, y, 0xFF0000FF);
			x++;
		}
	}
}

int	main(void)
{
	mlx_t	*mlx;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Line", true);
	if (!mlx)
		sexit(1);
	drawline(
		mlx,
		(struct s_vec2){ .x = 0, .y = 0},
		(struct s_vec2){ .x = 300, .y = 30});
	mlx_loop(mlx);
	mlx_terminate(mlx);
	sexit(1);
}
