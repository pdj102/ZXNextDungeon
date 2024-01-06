/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - close

**************************************************/
#include <inttypes.h>

#include "object_action_close.h"

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

uint8_t object_action_is_closeable(object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_OPEN:
        return 1;
    default:
        return 0;
    }
}

uint8_t object_action_close(object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_OPEN:
        obj->subtype=DOOR_CLOSED;
        obj->tilemap_tile.tile_id=43;
        obj->blocking = 1;
        return 1;
    default:
        return 0;
    }
}

object_t *object_action_close_findat(uint8_t x, uint8_t y)
{
    object_t *obj_p;

    for (obj_p = object_dungeon_list_first_at(x, y); obj_p; obj_p = object_dungeon_list_next_at(obj_p, x, y))
    {
        if (object_action_is_closeable(obj_p) )
        {
            return obj_p;
        }
    }
    return 0;
}