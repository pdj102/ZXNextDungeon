/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - open

**************************************************/
#include <stdint.h>

#include "object_open.h"

#include "object.h"
#include "object_list.h"
#include "object_dungeon_list.h"
#include "object_destroy.h"
#include "object_drop.h"

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

uint8_t object_open_is(object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_CLOSED:
    case CHEST_LARGE:
        return 1;
    default:
        return 0;
    }
}

uint8_t object_open(object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_CLOSED:
        obj->subtype=DOOR_OPEN;
        obj->tilemap_tile.tile_id=45;
        obj->blocking = 0;
        break;
    case CHEST_LARGE:
        object_drop_all(obj);
        object_destroy(obj);
        break;
    default:
        return 0;
    }
    return 1;
}