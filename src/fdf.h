/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:34:53 by brenohildeb       #+#    #+#             */
/*   Updated: 2023/11/04 15:44:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../kit/types/file.h"
# include "../kit/types/vec2.h"
# include "../kit/types/vec3.h"
# include "../kit/types/vec3_vector.h"
# include "../kit/types/rgba.h"
# include "../kit/types/rgba_vector.h"
# include "MLX42/MLX42.h"

typedef struct s_fdf			*t_fdf;
typedef struct s_map			*t_map;
typedef struct s_properties		*t_properties;
typedef struct s_extra			*t_extra;
typedef struct s_point			*t_point;

struct s_fdf {
	mlx_t			*mlx;
	t_map			map;	
	t_file			file;
	t_properties	properties;
	t_extra			extra;
};

struct s_map {
	t_rgba_vector	color;
	t_vec3_vector	position;
	t_i32			width;	
	t_i32			height;
};

struct s_properties {
	struct s_vec3	location;
	struct s_vec3	rotation;
	struct s_vec3	scale;
};

struct s_extra {
	t_i32	max_z;
	t_i32	min_z;
};

struct s_point {
	struct s_rgba	color;
	struct s_vec3	position;
};

/* old */
void	drawline(mlx_image_t *img, struct s_point p0, struct s_point p1);
void	bresenham(mlx_image_t *img, struct s_point p0, struct s_point p1);
void	rotate_isometric(struct s_point *p);
void	scale(struct s_point *p);
void	move_back_from_origin(t_map map, struct s_point *p);
void	move_to_origin(t_map map, struct s_point *p);
void	normalize_z(struct s_point *p);
void	centralize(t_map map, struct s_point *p);

/* main functions */
void	validate_args(int argc, char *argv[]);
void	parse_file(t_file file, t_map map);
void	render_map(t_fdf fdf);

/* helper functions */
void	init_extra(t_extra *extra);
void	init_fdf(t_fdf *fdf);
void	init_map(t_map *map);
void	init_properties(t_properties *properties);
void	handle_space_or_newline(
	t_file file, 
	t_map map, 
	t_vec2 coordinates, 
	t_u32 *index);
void	handle_number_and_color(
	t_file file,
	t_map map,
	t_vec2 coordinates,
	t_u32 *index);

#endif
