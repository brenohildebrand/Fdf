/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:34:53 by brenohildeb       #+#    #+#             */
/*   Updated: 2023/10/31 00:31:52 by bhildebr         ###   ########.fr       */
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

typedef struct s_map			*t_map;
typedef struct s_point			*t_point;
typedef struct s_point_vector	*t_point_vector;

struct s_map {
	t_rgba_vector	color;
	t_vec3_vector	position;
	t_i32			width;	
	t_i32			height;
};

void	init_map(t_map *map);

void	validate_args(int argc, char *argv[]);
void	validate_argc(int argc);
void	validate_argv(char *argv[]);

void	parse_file(t_file file, t_map map);
void	parse_space_or_newline(
	t_file file, 
	t_map map, 
	t_vec2 coordinates, 
	t_u32 *index);
void	parse_number_and_color(
	t_file file,
	t_map map,
	t_vec2 coordinates,
	t_u32 *index);

void	render_map(t_map map);

#endif
