/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - move

**************************************************/
#include <inttypes.h>

#include "object_action_move.h"

#include "object.h"
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

uint8_t object_action_move_is_movable(object_t *obj)
{
    // TODO return false for non movable objects
    return 1;
}
uint8_t object_action_move_to(object_t *obj, uint8_t x, uint8_t y)
{
    if (object_action_move_isblocked(x, y))
    {
        return 0;
    }

    // TODO test if object is moveable

    obj->x = x;
    obj->y = y;

    return 1;
}

uint8_t object_action_move_by(object_t *obj, int8_t dx, int8_t dy)
{
    return object_action_move_to(obj, obj->x + dx, obj->y + dy);
}

uint8_t object_action_move_isblocked(uint8_t dungeon_x, uint8_t dungeon_y)
{
    // check if move is blocked by dungeon map tile e.g. wall
    if (dungeonmap_tile_is_blocked(dungeon_x, dungeon_y))
    {
        return 1;
    }
    // check if move is blocked by ablocking object e.g. a closed door
    return object_isblocking(dungeon_x, dungeon_y);
}