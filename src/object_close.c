/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - close

**************************************************/
#include <stdint.h>

#include "object_close.h"

#include "object.h"
#include "object_list.h"

#include "dungeonmap.h"

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

uint8_t object_close_is(const object_t *obj_p)
{
    switch (obj_p->subtype)
    {
    case DOOR_OPEN:
        return 1;
    default:
        return 0;
    }
}

uint8_t object_close(object_t *obj_p)
{
    switch (obj_p->subtype)
    {
    case DOOR_OPEN:
        // TODO cant close a door if it is blocked by something blocking like a creature
        obj_p->subtype=DOOR_CLOSED;
        obj_p->tilemap_tile.tile_id=19;
        obj_p->blocking = 1;
        dungeonmap_setobjflags(obj_p->x, obj_p->y);        
        return 1;
    default:
        return 0;
    }
}