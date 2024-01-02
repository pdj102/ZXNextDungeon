/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - take

**************************************************/
#include <inttypes.h>

#include "object_action_pickup.h"

#include "object.h"

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

uint8_t object_action_is_pickup(object_t *obj)
{
    return 1;
}

uint8_t object_action_pickup(object_t *obj_topickup, object_t *obj_container)
{
    object_remove_from_dungeon_list(obj_topickup);
    return object_add_object_to_object_list(obj_topickup, obj_container);
}

object_t *object_action_pickup_findat(uint8_t x, uint8_t y)
{
    object_t *obj_ptr;

    for (obj_ptr = object_dungeon_list_first(); obj_ptr; obj_ptr = object_list_next(obj_ptr))
    {
        if (object_action_is_pickup(obj_ptr) && obj_ptr->x == x && obj_ptr->y == y)
        {
            return obj_ptr;
        }
    }
    return obj_ptr;
}