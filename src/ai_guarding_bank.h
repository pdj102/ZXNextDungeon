/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - guarding state

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_GUARDING_BANK_H 
    #define AI_GUARDING_BANK_H 

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
void ai_guarding_b(creature_t *attacker_p);

#endif