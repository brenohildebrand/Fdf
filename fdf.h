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
# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_shared			*t_shared;
typedef struct s_file			*t_file;
typedef struct s_map			*t_map;
typedef struct s_point			*t_point;
typedef struct s_position		*t_position;
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
	unsigned char	*address;
	unsigned int	size;
};

struct s_map {
	t_point			*address;
	unsigned int	size;
	unsigned int	width;
	unsigned int	height;
	unsigned int	length;
	char			*cursor;
};

struct s_point {
	t_position	position;
	int			color;
};

struct s_position {
	double	x;
	double	y;
	double	z;
};

struct s_framebuffer{
	int				*pixels;
	unsigned int	size;
	unsigned int	width;
	unsigned int	height;
	unsigned int	length;
};

struct s_window {
	void	*mlx;
	void	*window;
	void	*image;
};

t_shared		get_shared(void);
void			print(char *message);
void			validate_args(void);
void			read_file(void);
void			create_map_from_file(void);
t_point			create_point_from_map(void);
void			*custom_malloc(unsigned int size);
void			raise_error(unsigned char exit_code);
int				hex_to_number(unsigned char digit);
unsigned int	get_true_map_width(void);
void			create_framebuffer_from_map(void);
void			create_window_from_framebuffer(void);
void			put_pixel(int x, int y, int color);
t_point			transform_one_from(t_point point);
t_point			transform_two_from(t_point point);
void			newline_update(void);
void			isometrify(t_point point);
void			scale(t_point point);
void			centralize(t_point point);

#endif