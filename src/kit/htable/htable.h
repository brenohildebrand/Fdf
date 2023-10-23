/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:14:34 by bhildebr          #+#    #+#             */
/*   Updated: 2023/10/23 15:41:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTABLE_H
# define HTABLE_H

# include "../mem/mem.h"
# include "../status/status.h"
# include <stdlib.h>

/**
 * Okay. You won't be able to copy. You have to implement this your way.
 * A hash table is simply an array of entries (key, value) that are accessed
 * by using arr[hash(key) % sizeof(array)]. If two hashes match, just iterate till
 * you find an empty slot in the array of entries. If the hash table is 1/3 of its max size
 * double it, copying all the previous items and assign them to new indexes with the new modulo.
 * Let the user set the initial size since copying it will be a slow process considering it's a copy
 * and a calculation of n hashes and its module. Optimizations aside, that's how it's done most of the time.
*/

# define HTABLE_INITIAL_LENGTH 16

typedef struct s_htable {
	t_usize		element;
	t_u32		element_size;
	t_dbuffer	*entries;
}	t_htable;

typedef struct s_htable_entry {
	t_u8	key;
	t_usize	value;
}	t_htable_entry;

t_status	htable_create();
t_status	htable_get();
t_status	htable_set();
t_status	htable_length();
t_status	htable_iterator();
t_status	htable_next();
t_status	htable_destroy();

t_status	htable_malloc();
t_status	htable_init();

#endif