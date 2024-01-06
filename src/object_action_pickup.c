/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - pickup

**************************************************/
#include <inttypes.h>

#include "object_action_pickup.h"

#include "object.h"
#include "object_list.h"
#include "object_dungeon_list.h"

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
    // Physical or creature objects cannot be picked up
    if (obj->class == PHYSICAL || obj->class == CREATURE)
    {
        return 0;
    }
    // Everything else can be picked up
    return 1;
}

uint8_t object_action_pickup(object_t *obj_topickup, object_t *obj_container)
{
    object_dungeon_list_remove(obj_topickup);
    object_list_add(obj_topickup, obj_container);

    return 1;
}

object_t *object_action_pickup_find_first_at(uint8_t x, uint8_t y)
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

object_t *object_action_pickup_find_next_at(object_t *obj_ptr, uint8_t x, uint8_t y)
{
    for (; obj_ptr; obj_ptr = object_list_next(obj_ptr))
    {
        if (object_action_is_pickup(obj_ptr) && obj_ptr->x == x && obj_ptr->y == y)
        {
            return obj_ptr;
        }
    }
    return obj_ptr;
}