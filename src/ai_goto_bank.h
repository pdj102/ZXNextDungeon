/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - guarding state

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_GOTO_BANK_H 
    #define AI_GOTO_BANK_H 

#include "ai.h"

/***************************************************
 * types
 ***************************************************/

typedef enum goto_result {GOTO_NA, GOTO_SUCCESS, GOTO_FAIL, GOTO_REACHED} goto_result_t;

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
uint8_t ai_set_goto_b(ai_t *ai_p, uint8_t x, uint8_t y);

/**
 * AI takes turn
 * 
 * @return void
 */
goto_result_t ai_goto_b( ai_t *ai_p );

#endif