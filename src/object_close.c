/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - close

**************************************************/
#include <stdint.h>

#include "object_close.h"

#include "object.h"
#include "object_list.h"
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

uint8_t object_close_is(const object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_OPEN:
        return 1;
    default:
        return 0;
    }
}

uint8_t object_close(object_t *obj)
{
    switch (obj->subtype)
    {
    case DOOR_OPEN:
        // TODO cant close a door if it is blocked by something blocking like a creature
        obj->subtype=DOOR_CLOSED;
        obj->tilemap_tile.tile_id=19;
        obj->blocking = 1;
        return 1;
    default:
        return 0;
    }
}