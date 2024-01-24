/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The creature code - move action

    Code is banked do not call directly

 ***************************************************/
#include "creature_move.h"

#include <stdint.h>

#include "creature.h"

#include "object_move.h"


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