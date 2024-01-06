/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - open

**************************************************/
#include <inttypes.h>

#include "object_action_open.h"

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

uint8_t object_action_move_is_openable(object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_CLOSED:
        return 1;
    default:
        return 0;
    }
}

uint8_t object_action_open(object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_CLOSED:
        obj->subtype=DOOR_OPEN;
        obj->tilemap_tile.tile_id=45;
        obj->blocking = 0;
        return 1;
    default:
        return 0;
    }
}

object_t *object_action_open_findat(uint8_t x, uint8_t y)
{
    object_t *obj_ptr;

    for (obj_ptr = object_dungeon_list_first(); obj_ptr; obj_ptr = object_list_next(obj_ptr))
    {
        if (object_action_move_is_openable(obj_ptr) && obj_ptr->x == x && obj_ptr->y == y)
        {
            return obj_ptr;
        }
    }
    return obj_ptr;
}