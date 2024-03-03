/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - melee strike

    Creature attempts a melee strike on another creature

 ***************************************************/

#ifndef CREATURE_ACTION_MELEE_STRIKE_H 
    #define CREATURE_ACTION_MELEE_STRIKE_H 

#include <stdint.h>

#include "creature.h"

#include "util.h"

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
 * @param attacker_p    creature_t
 * @param d             direction_t
 *
 * @return 1 if action successful or 0 failed
 */
uint8_t creature_action_melee_strike_dir(creature_t *attacker_p, direction_t d);

/**
 * Attempt a melee strike
 * 
 * @param attacker_p    creature_t
 * @param dx            dx
 * @param dy            dy
 *
 * @return 1 if action successful or 0 failed
 */
uint8_t creature_action_melee_strike_d(creature_t *attacker_p, int8_t dx, int8_t dy);

/**
 * Attempt a melee strike
 *
 * @param *attacker attacking creature
 * @param *target target creature
 * 
 * @return 1 if action successful or 0 failed
 */
uint8_t creature_action_melee_strike(creature_t *attacker, creature_t *target);

#endif