/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - pickup

**************************************************/
#include <inttypes.h>

#include "object_pickup.h"

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

uint8_t object_pickup_is(object_t *obj)
{
    // Physical or creature objects cannot be picked up
    if (obj->class == PHYSICAL || obj->class == CREATURE)
    {
        return 0;
    }
    // Everything else can be picked up
    return 1;
}

uint8_t object_pickup(object_t *obj_topickup, object_t *obj_container)
{
    object_dungeon_list_remove(obj_topickup);
    object_list_add(obj_topickup, obj_container);

    return 1;
}

object_t *object_pickup_find_first_at(uint8_t x, uint8_t y)
{
    object_t *obj_p;

    for (obj_p = object_dungeon_list_first_at(x, y); obj_p; obj_p = object_dungeon_list_next_at(obj_p, x, y))    
    {
        if (object_pickup_is(obj_p))
        {
            return obj_p;
        }
    }
    return 0;
}

object_t *object_pickup_find_next_at(object_t *obj_p, uint8_t x, uint8_t y)
{
    for (; obj_p; obj_p = object_dungeon_list_next_at(obj_p, x, y))
    {
        if (object_pickup_is(obj_p) )
        {
            return obj_p;
        }
    }
    return 0;
}