/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The creature code - move action


 ***************************************************/
#include "creature_move.h"

#include <stdint.h>

#include "creature.h"

#include "object_move.h"

#include "text.h"


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

uint8_t creature_move_by(creature_t *creature_p, int8_t dx, int8_t dy)
{
    // Creature attempts move so decrease energy 
    creature_p->energy = 0;

    // TODO deal with not being able to move e.g. due to an effect or status
    
    return object_move_by(creature_p->obj_p, dx, dy);
}

uint8_t creature_move_dir(creature_t *creature_p, direction_t d)
{
    switch (d)
    {
    case N:
       return creature_move_by(creature_p, 0, -1);
    case S:
        return creature_move_by(creature_p, 0, 1);
    case W:
        return creature_move_by(creature_p, -1, 0);               
    case E:
        text_printf("E");
        return creature_move_by(creature_p, 1, 0);
    default:
        return 0;
    }
}