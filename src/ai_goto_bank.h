/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - guarding state

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_GOTO_BANK_H 
    #define AI_GOTO_BANK_H 

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
 * @brief Set creatures goto target location
 * 
 * @param creature_p 
 * @param x 
 * @param y 
 * @return uint8_t 
 */
uint8_t ai_set_goto_b(creature_t *creature_p, uint8_t x, uint8_t y);

/**
 * AI takes turn
 * 
 * @return void
 */
uint8_t ai_goto_b( creature_t *creature_p);

#endif