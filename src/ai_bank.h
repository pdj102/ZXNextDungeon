/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The ai code

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_BANK_H 
    #define AI_BANK_H 

#include "object.h"
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
 * Init the AI
 *
 * @param obj_ptr pointer to the ai object
 * @return void
 */
void ai_init_b(ai_t *ai_p);

/**
 * AI takes turn
 * 
 * @return void
 */
void ai_turn_b( void );


#endif