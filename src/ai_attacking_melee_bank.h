/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - attacking melee

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_ATTACKING_MELEE_BANK_H 
    #define AI_ATTACKING_MELEE_BANK_H 

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
void ai_attacking_melee_b(creature_t *attacker_p);

#endif