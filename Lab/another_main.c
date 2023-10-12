/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:41:01 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/12 11:48:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"

#define WIDTH 256
#define HEIGHT 256

static void	ft_error(void)
{
}

static void	ft_hook(void *param)
{
	const mlx_t*	mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Hey Soul Sister", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}