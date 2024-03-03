/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - open

    Creature attempts to open an object

 ***************************************************/

#include "creature_action_open.h"

#include <stdint.h>

#include "object.h"
#include "object_open.h"

#include "dungeonmap_list.h"

#include "globaldata.h"

#include "util.h"

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

object_t *creature_action_open_dir(creature_t *creature_p, direction_t d)
{
    int8_t dx, dy;

    util_dir_to_dxdy(d, &dx, &dy);

    return creature_action_open_d(creature_p, dx, dy);
}

object_t *creature_action_open_d(creature_t *creature_p, int8_t dx, int8_t dy)
{
    object_t *obj_p = 0;
    uint8_t x, y;

    // reduce attackers energy 
    creature_p->energy = 0;    

    x = creature_p->obj_p->x + dx;
    y = creature_p->obj_p->y + dy;

    if ( obj_p = dungeonmap_list_first_is_at(x, y, object_open_is))
    {
        object_open(obj_p);
    }
    return obj_p;
}

