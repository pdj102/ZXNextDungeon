/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The creature code - move action

    Code is banked do not call directly

 ***************************************************/

#ifndef CREATURE_MOVE_H 
    #define CREATURE_MOVE_H 

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
 * Creature move action
 *
 * @return void
 */
uint8_t creature_move_by(creature_t *creature_p, int8_t dx, int8_t dy);

#endif