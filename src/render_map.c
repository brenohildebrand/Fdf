/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:12:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 17:57:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "fdf.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

#define WIDTH (1920)
#define HEIGHT (1080)

static void	transform_and_draw(t_fdf fdf, mlx_image_t *img, t_u32 p0_index, t_u32 p1_index)
{
	struct s_point	p0;
	struct s_point	p1;

	p0.position = fdf->map->position->data[p0_index];
	p1.position = fdf->map->position->data[p1_index];
	p0.color = fdf->map->color->data[p0_index];
	p1.color = fdf->map->color->data[p1_index];
	normalize_z(fdf, &p0);
	normalize_z(fdf, &p1);
	scale(fdf, &p0);
	scale(fdf, &p1);
	move_to_origin(fdf, &p0);
	move_to_origin(fdf, &p1);
	rotate_isometric(fdf, &p0);
	rotate_isometric(fdf, &p1);
	move_back_from_origin(fdf, &p0);
	move_back_from_origin(fdf, &p1);
	centralize(fdf, &p0);
	centralize(fdf, &p1);
	bresenham(img, p0, p1);
}

static void	foreach_pair(t_fdf fdf, mlx_image_t *img, t_u32 x, t_u32 y)
{
	t_u32	p0_index;
	t_u32	p1_index;
	t_u32	p2_index;
	
	p0_index = x + y * fdf->map->width;
	if (x + 1 < fdf->map->width)
	{
		p1_index = x + 1 + y * fdf->map->width;
		transform_and_draw(fdf, img, p0_index, p1_index);
	}
	if (y + 1 < fdf->map->height)
	{
		p2_index = x + (y + 1) * fdf->map->width;
		transform_and_draw(fdf, img, p0_index, p2_index);
	}
}

static void	foreach_point(t_fdf fdf)
{
	mlx_image_t	*img;
	t_u32		x;
	t_u32		y;

	img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(fdf->mlx, img, 0, 0)) < 0)
		sexit(1);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while(x < fdf->map->width)
		{
			foreach_pair(fdf, img, x, y);
			x++;
		}
		y++;
	}
}

void	ft_hook(void *param)
{
	t_fdf	fdf;

	fdf = (t_fdf)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		control_key_up(fdf);
	foreach_point(fdf);
}

void	render_map(t_fdf fdf)
{
	mlx_image_t			*img;
	
	fdf->properties->rotation->x = -54;
	mlx_set_setting(MLX_MAXIMIZED, true);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!(fdf->mlx))
		sexit(1);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
}
