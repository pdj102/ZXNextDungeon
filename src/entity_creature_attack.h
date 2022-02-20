/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Creature entity attack action

 ***************************************************/

#ifndef ENTITY_CREATURE_ATTACK_H 
    #define ENTITY_CREATURE_ATTACK_H 

#include <inttypes.h>

#include "entity.h"
#include "dice.h"
#include "entity_creature.h"

/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/


/**
 * @brief Attempt to strike in direction
 * 
 * @param creature_ptr creature that performs the strike
 * @param dx strike in direction delta x 
 * @param dy strike in direction  delta y
 * 
 * @return 1 if attempted a strike or 0 if nothing to strike at
 */
uint8_t entity_creature_strike(creature_t *attacker_creature_ptr, int8_t dx, int8_t dy);



#endif