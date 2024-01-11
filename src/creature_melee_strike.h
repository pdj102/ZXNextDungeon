/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - melee strike

    Creature attempts a melee strike on another creature

 ***************************************************/

#ifndef CREATURE_MELEE_STRIKE_H 
    #define CREATURE_MELEE_STRIKE_H 

#include <stdint.h>

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
 * Attempt a melee strike
 *
 * @param *attacker attacking creature
 * @param *target target creature
 * 
 * @return uint8_t  1 if action successful or 0 failed
 */
uint8_t creature_melee_strike(creature_t *attacker, creature_t *target);

#endif