/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:12:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/31 01:14:10 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "fdf.h"
#include "MLX42/MLX42.h"

#define WIDTH (1920)
#define HEIGHT (1080)

void	render_map(t_map map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!mlx)
		sexit(1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		sexit(1);
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
