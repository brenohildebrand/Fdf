/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:20:31 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/24 16:32:48 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	validate_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "Invalid number of arguments.\n", 29);
		exit(1);
	}
}
