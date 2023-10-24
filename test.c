/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brenohildebrand <brenohildebrand@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:40:39 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 03:30:29 by brenohildeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/kit/dbuffer/dbuffer.h"
#include <stdio.h>

#define DEFAULT_DBUFFER_METADATA (t_dbuffer_metadata){.element_size = 1, .max_number_of_elements = 16, .number_of_elements = 0}

typedef struct s_point {
	int x;
	int y;
	int z;
}	t_point;

t_status	main(void)
{
	t_dbuffer	dbuffer;
	t_status	status;

	status = dbuffer_create(&dbuffer, DEFAULT_DBUFFER_METADATA);
	if (status == ko)
		return (ko);
	status = dbuffer_set(&dbuffer, 4, (t_point) {
		.x = 3,
		.y = 2,
		.z = 5
	});
	status = dbuffer_destroy(&dbuffer);
	if (status == ko)
		return (ko);
	return (ok);
}