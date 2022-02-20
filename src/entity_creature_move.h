/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Creature entity move action

 ***************************************************/

#ifndef ENTITY_CREATURE_MOVE_H 
    #define ENTITY_CREATURE_MOVE_H 

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
 * @brief Attempt to move creature in direction or if way is blocked try strike action
 * 
 * @param creature_ptr creature to move
 * @param dx move delta x 
 * @param dy move delta y
 * @return 1 if success 0 if unable to move or strike
 */
uint8_t entity_creature_move_or_strike(creature_t *creature_ptr, int8_t dx, int8_t dy);

/**
 * @brief Attempt to move creature in direction
 * 
 * @param creature_ptr creature to move
 * @param dx move delta x 
 * @param dy move delta y
 * 
 * @return 1 if successfully moved or 0 if unable to move
 */
uint8_t entity_creature_move(creature_t *creature_ptr, int8_t dx, int8_t dy);


#endif