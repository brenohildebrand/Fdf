#ifndef ELEMENT_H
# define ELEMENT_H

# include "../mem/mem.h"

typedef struct s_element_metadata {
    t_u32   type;
    
}   t_element_metadata;

typedef struct s_element {
    t_usize             data;
    t_element_metadata  metadata;
}   t_element;

#endif