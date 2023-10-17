/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:53:55 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/17 17:17:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init()
{
	// parse args
	// read map
	// validate map
	// create window and init mlx
}

void	loop()
{
	render(/* map */);
}

void	render(/* map */)
{
	map_scale(/* map */);
	map_rotate(/* */); // rotate on z
	map_rotate(/* */); // rotate on x
	map_center();
	map_draw();
}

int	main(int argc, char *argv[])
{
	init();
	while (1)
		loop();
	return (0);
}