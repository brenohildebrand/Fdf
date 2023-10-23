/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbuffer_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:25:54 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/23 17:50:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbuffer.h"

t_status	dbuffer_malloc(t_dbuffer *dbuffer, t_dbuffer_metadata *metadata)
{
	t_u32	total_size;

	total_size = metadata->element_size * metadata->max_number_of_elements;
	dbuffer->address = (t_usize)malloc(total_size);
	if (dbuffer->address == 0)
		return (ko);
	return (ok);
}