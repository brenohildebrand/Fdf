/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:20:23 by marvin            #+#    #+#             */
/*   Updated: 2023/11/25 20:20:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_window	create_window(void)
{
	t_window	window;

	window = custom_malloc(sizeof(struct s_window));
	window->mlx = mlx_init();
	if (window->mlx == (void *)0)
		raise_error(250);
	window->window = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Fdf");
	if (window->window == (void *)0)
		raise_error(249);
	return (window);
}

static int	esc_hook(int keycode, void *ptr)
{
	t_shared	shared;

	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		shared = get_shared();
		mlx_destroy_window(shared->window->mlx, shared->window->window);
		mlx_destroy_display(shared->window->mlx);
	}
}

static void	init_window(t_window window, t_framebuffer framebuffer)
{
	unsigned int	length;
	unsigned int	i;
	unsigned int	j;
	int				color;

	length = 0;
	while (length < framebuffer->length)
	{
		i = length % framebuffer->width;
		j = length / framebuffer->width;
		color = framebuffer->pixels[length];
		put_pixel(i, j, color);
		length++;
	}
	mlx_key_hook(window->window, esc_hook, NULL);
	mlx_loop(window->mlx);
}

void	create_window_from_framebuffer(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->window = create_window();
	init_window(shared->window, shared->framebuffer);
}
