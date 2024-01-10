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
	window->should_close = 0;
	return (window);
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
	mlx_hook(window->window, 17, 1L << 3, close_hook, NULL);
	mlx_loop_hook(window->mlx, loop_hook, NULL);
	mlx_loop(window->mlx);
}

void	create_window_from_framebuffer(void)
{
	t_shared	shared;

	shared = get_shared();
	shared->window = create_window();
	init_window(shared->window, shared->framebuffer);
	mlx_destroy_display(shared->window->mlx);
	free(shared->window->mlx);
}
