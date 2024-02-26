/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - place

**************************************************/
#include <stdint.h>

#include "object_place.h"

#include "object.h"
#include "object_move.h"
#include "object_stepon.h"

#include "dungeonmap.h"
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


void object_place(object_t *const obj_p, uint8_t x, uint8_t y)
{
    // Place object
    obj_p->x = x;
    obj_p->y = y;    

    // Add object to dungeon map list
    dungeonmap_list_add(obj_p);

    // Set dungeon map tile object present flag at new location
    dungeonmap_tile_flag_set(x, y, DGN_FLAG_OBJECT);

    // If object is blocking set dungeon map tile blocking object flag 
    if (obj_p->blocking) { dungeonmap_tile_flag_set(x, y, DGN_FLAG_BLK_OBJECT); }    

    // Trigger any step_on events
    object_stepon_all(x, y);
}