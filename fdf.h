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

typedef struct s_shared	*t_shared;

struct s_shared {
	int		argc;
	char	**argv;
	void	*mlx;
	void	*window;
};

t_shared	get_shared(void);
void		print(char *message);
void		validate_args(void);

#endif