/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:52:59 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/28 16:11:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Kit/actions/actions.h"
#include "42-Kit/types/rmanager.h"

#include <stdlib.h>

t_i32	main(void)
{
	t_usize_avltree	rmanager;
	// t_i32	*number;
	// t_u8	*name;

	// rmanager = NULL;
	// number = malloc(sizeof(t_i32));
	// name = malloc(sizeof(t_u8));
	// insert_rmanager(&rmanager, (t_usize)number);
	// insert_rmanager(&rmanager, (t_usize)name);
	// destroy_rmanager(&rmanager);

	print("[ TESTING PRINT ]");
	rmanager = NULL; 
	for (int i = 1; i < 10001; i++)
		insert_rmanager(&rmanager, (t_usize)malloc(i));
	destroy_rmanager(&rmanager);
	return (0);	
}
