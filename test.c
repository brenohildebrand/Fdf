/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:40:39 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/23 18:26:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/kit/dbuffer/dbuffer.h"
#include <stdio.h>

#define DEFAULT_DBUFFER_METADATA (t_dbuffer_metadata){.element_size = 1, .max_number_of_elements = 16, .number_of_elements = 0}

t_status	main(void)
{
	t_dbuffer	dbuffer;
	t_status	status;

	status = dbuffer_create(&dbuffer, DEFAULT_DBUFFER_METADATA);
	if (status == ko)
		return (ko);
	status = dbuffer_destroy(&dbuffer);
	if (status == ko)
		return (ko);
	return (ok);
}