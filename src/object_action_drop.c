/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - drop

**************************************************/
#include <inttypes.h>

#include "object_action_drop.h"

#include "object.h"
#include "object_list.h"
#include "object_dungeon_list.h"
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

uint8_t object_action_is_drop(object_t *obj)
{
    // For now all objects can be dropped
    return 1;
}

uint8_t object_action_drop(object_t *obj_todrop, object_t *obj_container_ptr)
{
    object_list_remove(obj_todrop, obj_container_ptr);
    obj_todrop->x = obj_container_ptr->x;
    obj_todrop->y = obj_container_ptr->y;
    object_dungeon_list_add(obj_todrop);
    return 1;
}

uint8_t object_action_drop_all(object_t *obj_container_ptr)
{
    object_t *obj_p;

    while (obj_p = object_action_drop_find_first(obj_container_ptr))
    {
        object_action_drop(obj_p, obj_container_ptr);
    }

    /*
    while (obj_p)
    {
        object_action_drop(obj_p, obj_container_ptr);
        obj_p = object_action_drop_find_next(obj_p);
    }
    */
   return 1;
}

object_t *object_action_drop_find_first(object_t *obj_container_ptr)
{
    object_t *obj_ptr;

    for (obj_ptr = object_list_first(obj_container_ptr); obj_ptr; obj_ptr = object_list_next(obj_ptr))
    {
        if (object_action_is_drop(obj_ptr) )
        {
            return obj_ptr;
        }
    }
    return 0;
}

object_t *object_action_drop_find_next(object_t *obj_ptr)
{
    for (; obj_ptr; obj_ptr = object_list_next(obj_ptr))
    {
        text_print_string("*");
        if (object_action_is_drop(obj_ptr) )
        {
            return obj_ptr;
        }
    }
    return 0;
}