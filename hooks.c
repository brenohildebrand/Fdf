/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:01:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/01/11 13:19:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc_hook(int keycode, void *ptr)
{
	t_shared	shared;

	(void)ptr;
	if (keycode == 65307)
	{
		shared = get_shared();
		shared->window->should_close = 1;
	}
	return (0);
}

int	close_hook(void *ptr)
{
	t_shared	shared;

	(void)ptr;
	shared = get_shared();
	shared->window->should_close = 1;
	return (0);
}

int	loop_hook(void *ptr)
{
	t_shared	shared;

	(void)ptr;
	shared = get_shared();
	if (shared->window->should_close)
		mlx_destroy_window(shared->window->mlx, shared->window->window);
	return (0);
}
