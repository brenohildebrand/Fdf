/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:12:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 15:47:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "fdf.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

#define WIDTH (1920)
#define HEIGHT (1080)

static void	transform_and_draw(mlx_image_t *img, t_map map, t_u32 p0_index, t_u32 p1_index)
{
	struct s_point	p0;
	struct s_point	p1;

	p0.position = map->position->data[p0_index];
	p1.position = map->position->data[p1_index];
	p0.color = map->color->data[p0_index];
	p1.color = map->color->data[p1_index];
	// apply transforms to p0 and p1
	// normalize z
	normalize_z(&p0);
	normalize_z(&p1);
	// scale
	scale(&p0);
	scale(&p1);
	// move to origin
	move_to_origin(map, &p0);
	move_to_origin(map, &p1);
	// rotate
	rotate_isometric(&p0);
	rotate_isometric(&p1);
	// move back to place
	move_back_from_origin(map, &p0);
	move_back_from_origin(map, &p1);
	// centralize
	centralize(map, &p0);
	centralize(map, &p1);
	// drawline
	bresenham(img, p0, p1);
}

static void	foreach_pair(mlx_image_t *img, t_map map, t_u32 x, t_u32 y)
{
	t_u32	p0_index;
	t_u32	p1_index;
	t_u32	p2_index;
	
	p0_index = x + y * map->width;
	if (x + 1 < map->width)
	{
		p1_index = x + 1 + y * map->width;
		transform_and_draw(img, map, p0_index, p1_index);
	}
	if (y + 1 < map->height)
	{
		p2_index = x + (y + 1) * map->width;
		transform_and_draw(img, map, p0_index, p2_index);
	}
}

static void	foreach_point(mlx_t	*mlx, t_map map)
{
	mlx_image_t	*img;
	t_u32		x;
	t_u32		y;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0)) < 0)
		sexit(1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			foreach_pair(img, map, x, y);
			x++;
		}
		y++;
	}
}

void	ft_hook(t_fdf fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
		// update_rotation_x();
	foreach_point(fdf->mlx, fdf->map);
}

void	render_map(t_fdf fdf)
{
	mlx_image_t			*img;
	
	mlx_set_setting(MLX_MAXIMIZED, true);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!(fdf->mlx))
		sexit(1);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
}
