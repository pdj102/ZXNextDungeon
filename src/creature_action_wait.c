/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - wait

    Creature does nothing for a turn

 ***************************************************/

#include "creature_action_wait.h"

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

void creature_action_wait(creature_t *creature_p)
{
    // reduce creatures energy 
    creature_p->energy = 0;    
}

