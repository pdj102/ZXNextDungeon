/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - strike

**************************************************/
#include <stdint.h>

#include "object_strike.h"

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

uint8_t object_strike_is(object_t *obj_p)
{
    // All creatures can be striked 
    if (obj_p->class == CREATURE)
    {
        return 1;
    }
    // Everything else cannot
    return 0;
}

object_t *object_strike_find_first_at(uint8_t x, uint8_t y)
{
    object_t *obj_p;

    for (obj_p = object_dungeon_list_first_at(x, y); obj_p; obj_p = object_dungeon_list_next_at(obj_p, x, y))    
    {
        if (object_strike_is(obj_p))
        {
            return obj_p;
        }
    }
    return 0;
}

object_t *object_strike_find_next_at(object_t *obj_p, uint8_t x, uint8_t y)
{
    for (; obj_p; obj_p = object_dungeon_list_next_at(obj_p, x, y))
    {
        if (object_strike_is(obj_p) )
        {
            return obj_p;
        }
    }
    return 0;
}