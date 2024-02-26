/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - move

**************************************************/
#include <stdint.h>

#include "object_move.h"

#include "object.h"
#include "dungeonmap_list.h"
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

uint8_t object_move_to(object_t *const obj_p, uint8_t x, uint8_t y)
{
    uint8_t tmp_x = obj_p->x;
    uint8_t tmp_y = obj_p->y;
   
    if (object_move_isblocked(x, y))
    {
        return 0;
    }

    // TODO test if object is moveable

    // Move object
    obj_p->x = x;
    obj_p->y = y;

    // Set dungeon map tile object present flag at new location
    dungeonmap_tile_flag_set(x, y, DGN_FLAG_OBJECT);

    // If object is blocking set dungeon map tile blocking object flag 
    if (obj_p->blocking) { dungeonmap_tile_flag_set(x, y, DGN_FLAG_BLK_OBJECT); }    

    // Reset the object flags at the old location 
    dungeonmap_setobjflags(tmp_x, tmp_y);

    // Trigger any step_on events
    object_stepon_all(x, y);
    
    return 1;
}


uint8_t object_move_by(object_t *obj, int8_t dx, int8_t dy)
{
    return object_move_to(obj, obj->x + dx, obj->y + dy);
}

uint8_t object_move_isblocked(uint8_t dungeon_x, uint8_t dungeon_y)
{
    // TODO handle walking vs flying etc. Each object needs its own flags to indicate what blocks it

    // check if move is blocked by a wall or blocking object
    return (dungeonmap_tile_flag_test(dungeon_x, dungeon_y, DGN_FLAG_BLK_ALL | DGN_FLAG_WALL | DGN_FLAG_BLK_OBJECT));
}