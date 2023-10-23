/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbuffer_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:48:09 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/23 17:53:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbuffer.h"

t_status	dbuffer_init(t_dbuffer *dbuffer, t_dbuffer_metadata *metadata)
{
	t_u32	i;

	i = 0;
	while (i < (metadata->max_number_of_elements * metadata->element_size))
	{
		((t_u8 *)(dbuffer->address))[i] = 0;
		i++;
	}
	dbuffer->metadata = *metadata;
	return (ok);
}