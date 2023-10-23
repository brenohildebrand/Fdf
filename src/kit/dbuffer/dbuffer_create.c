/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbuffer_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:51:50 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/23 17:48:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbuffer.h"

t_status	dbuffer_create(t_dbuffer *dbuffer, t_dbuffer_metadata metadata)
{
	t_status	status;

	status = dbuffer_malloc(dbuffer, &metadata);
	if (status == ko)
		return (ko);
	status = dbuffer_init(dbuffer, &metadata);
	if (status == ko)
		return (ko);
	return (ok);	
}