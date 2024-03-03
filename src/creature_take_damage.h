/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - damage

    Attempt to apply damage to a creature

 ***************************************************/

#ifndef CREATURE_TAKE_DAMAGE_H 
    #define CREATURE_TAKE_DAMAGE_H 

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
 * Apply damage to target creature. 
 * 
 * Applies target's damage modifiers which may reduce or increase the damage 
 *
 * @param *target_p target creature
 * @param damage base damage amount
 * @param type type of damage
 * 
 * @return uint8_t actual damage applied
 */
uint8_t creature_take_damage(creature_t *target_p, uint8_t base_damage, damage_type_t type);

#endif