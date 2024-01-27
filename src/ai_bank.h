/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The ai code

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_BANK_H 
    #define AI_BANK_H 

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
 * AI takes turn
 * 
 * @return void
 */
void ai_turn_b( creature_t *creature_p );

/**
 * Notify AI of attack by another creature
 * 
 * @return void
 */
void ai_is_attacked_b(creature_t *target_p, creature_t *attacker_p);

#endif