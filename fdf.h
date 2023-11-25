/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:08:29 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 18:08:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

typedef struct s_shared			*t_shared;
typedef struct s_file			*t_file;
typedef struct s_map			*t_map;
typedef struct s_framebuffer	*t_framebuffer;
typedef struct s_window			*t_window;

struct s_shared {
	int				argc;
	char			**argv;
	t_file			file;
	t_map			map;
	t_framebuffer	framebuffer;
	t_window		window;
};

struct s_file {
	void			*address;
	unsigned int	size;
};

struct s_map {};

struct s_framebuffer{};

struct s_window {
	void	*mlx;
	void	*window;
};

t_shared	get_shared(void);
void		print(char *message);
void		validate_args(void);
void		read_file();

#endif