/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Creature entity pickup action

 ***************************************************/

#ifndef ENTITY_CREATURE_PICKUP_H 
    #define ENTITY_CREATURE_PICKUP_H 

#include <inttypes.h>

#include "entity.h"
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
 * @brief Attempt to pickup 
 * 
 * @param creature_ptr creature that performs the pickup
 * 
 * @return 1 if attempted pickup or 0 if nothing to pickup
 */
uint8_t entity_creature_pickup(creature_t *creature_ptr);

#endif