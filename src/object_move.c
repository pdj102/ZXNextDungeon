/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - move

**************************************************/
#include <stdint.h>

#include "object_move.h"

#include "object.h"
#include "object_dungeon_list.h"
#include "object_stepon.h"
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

uint8_t object_move_is(object_t *obj)
{
    // TODO return false for non movable objects
    return 1;
}

uint8_t object_move_to(object_t *obj_p, uint8_t x, uint8_t y)
{
    if (object_move_isblocked(x, y))
    {
        return 0;
    }

    // TODO test if object is moveable

    obj_p->x = x;
    obj_p->y = y;

    object_stepon_all(x, y);
    return 1;
}

uint8_t object_move_by(object_t *obj, int8_t dx, int8_t dy)
{
    return object_move_to(obj, obj->x + dx, obj->y + dy);
}

uint8_t object_move_isblocked(uint8_t dungeon_x, uint8_t dungeon_y)
{
    // check if move is blocked by dungeon map tile e.g. wall
    if (dungeonmap_tile_is_blocked(dungeon_x, dungeon_y, DGN_FLAG_BLK_ALL | DGN_FLAG_WALL))
    {
        return 1;
    }
    // check if move is blocked by a blocking object e.g. a closed door
    return object_dungeon_list_isblocking_at(dungeon_x, dungeon_y);
}