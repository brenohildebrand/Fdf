/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:27:43 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/23 15:36:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "htable.h"

t_status	htable_create(t_htable **address, t_u32 element_size)
{
	t_status	status;

	status = htable_malloc(address, element_size);
	if (status == ko)
		return (ko);
	status = htable_init(*address, element_size);
	if (status == ko)
		return (ko);
	return (ok);
}