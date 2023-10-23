/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbuffer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:41:43 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/23 18:29:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBUFFER_H
# define DBUFFER_H

# include "../mem/mem.h"
# include "../status/status.h"
# include <stdlib.h>

typedef struct s_dbuffer_metadata {
	t_u32	element_size;
	t_u32	number_of_elements;
	t_u32	max_number_of_elements;
}	t_dbuffer_metadata;

typedef struct s_dbuffer {
	t_usize				address;
	t_dbuffer_metadata	metadata;
}	t_dbuffer;

t_status	dbuffer_create(t_dbuffer *dbuffer, t_dbuffer_metadata metadata);
t_status	dbuffer_get(t_dbuffer *dbuffer, t_i32 index);
t_status	dbuffer_insert(t_dbuffer *dbuffer, t_i32 index, t_usize element_address);
t_status	dbuffer_destroy(t_dbuffer *dbuffer);

t_status	dbuffer_malloc(t_dbuffer *dbuffer, t_dbuffer_metadata *metadata);
t_status	dbuffer_init(t_dbuffer *dbuffer, t_dbuffer_metadata *metadata);

#endif