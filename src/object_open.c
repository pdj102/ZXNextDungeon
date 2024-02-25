/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - open

**************************************************/
#include <stdint.h>

#include "object_open.h"

#include "object.h"
#include "object_list.h"
#include "object_destroy.h"
#include "object_drop.h"

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

uint8_t object_open_is(object_t *obj_p)
{
    switch (obj_p->subtype)
    {
    case DOOR_CLOSED:
    case CHEST_LARGE:
        return 1;
    default:
        return 0;
    }
}

uint8_t object_open(object_t *obj_p)
{
    switch (obj_p->subtype)
    {
    case DOOR_CLOSED:
        obj_p->subtype=DOOR_OPEN;
        obj_p->tilemap_tile.tile_id=18;
        obj_p->blocking = 0;
        dungeonmap_setobjflags(obj_p->x, obj_p->y);
        break;
    case CHEST_LARGE:
        object_drop_all(obj_p);
        object_destroy(obj_p);
        break;
    default:
        return 0;
    }
    return 1;
}