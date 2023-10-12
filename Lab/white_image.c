/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:52:41 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/12 11:59:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "MLX42/MLX42.h"

// Bytes Per Pixel
#define BPP sizeof(int32_t)

int32_t	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(256, 256, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, 128, 128);
	memset(img->pixels, 0xFF, img->width * img->height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}