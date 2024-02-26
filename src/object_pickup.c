/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - pickup

**************************************************/
#include <stdint.h>

#include "object_pickup.h"

#include "object.h"
#include "object_list.h"
#include "object_remove.h"

#include "dungeonmap_list.h"

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
    object_remove(obj_topickup);
    object_list_add(obj_topickup, obj_container);

    return 1;
}
