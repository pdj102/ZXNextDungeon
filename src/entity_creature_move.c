/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    Creature entity move action

 ***************************************************/
#include "entity_creature_move.h"

#include <inttypes.h>

#include "entity.h"
#include "entity_creature.h"
#include "entity_creature_attack.h"


/***************************************************
 * private types
 ***************************************************/

/***************************************************
 * private function prototypes
 ***************************************************/

/***************************************************
 * private variables
 ***************************************************/


/***************************************************
 * function definitions
 ***************************************************/


uint8_t entity_creature_move_or_strike(creature_t *creature_ptr, int8_t dx, int8_t dy)
{
    if (entity_creature_move(creature_ptr, dx, dy))
    {
        // succeeded in moving 
        return 1;
    }
    // try striking instead
    return (entity_creature_strike(creature_ptr, dx, dy));
}

uint8_t entity_creature_move(creature_t *creature_ptr, int8_t dx, int8_t dy)
{
    uint8_t effort;

    if(entity_move(creature_ptr->entity_ptr, dx, dy))
    {
        // decrease entity energy by 10 - speed
        effort = (10 - creature_ptr->speed);
        entity_reduce_energy(creature_ptr->entity_ptr, effort);

        return 1;
    }
    return 0;
}
