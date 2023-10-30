/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:20:31 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/30 04:37:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include <unistd.h>
#include <stdlib.h>

void	validate_argc(int argc)
{
	if (argc != 2)
	{
		print("Invalid number of arguments.");
		exit(1);
	}
}
