/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - wait

    Creature waits for a turn

 ***************************************************/

#ifndef CREATURE_ACTION_WAIT_H 
    #define CREATURE_ACTION_WAIT_H 

#include "creature.h"


/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Creature does nothing for a turn
 * 
 * @param creature_p    creature_t
 *
 */
void creature_action_wait(creature_t *creature_p);


#endif