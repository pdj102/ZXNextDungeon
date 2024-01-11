/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

**************************************************/

#include <stdint.h>
#include <adt/p_forward_list.h>

#include "object_list.h"

#include "object.h"
#include "text.h"

/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * functions
 ***************************************************/

uint8_t object_list_add(object_t* obj_p, object_t* container_obj_p)
{
    p_forward_list_push_front(&container_obj_p->obj_list, obj_p);
    return 1;
}


uint8_t object_list_remove(object_t* obj_p, object_t* container_obj_p)
{
    p_forward_list_remove(&container_obj_p->obj_list, obj_p);
    return 1;
}

object_t *object_list_first(object_t *container_obj_p)
{
    return p_forward_list_front(&container_obj_p->obj_list);
}


object_t *object_list_next(object_t *obj_p)
{
    return p_forward_list_next(obj_p);
}
