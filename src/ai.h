/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The AI code

 ***************************************************/

#ifndef AI_H 
    #define AI_H 

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
 * Init the ai
 *
 * @param ai_ptr pointer to the ai object
 * @return void
 */
void ai_init(ai_t *ai_p);

/**
 * Ai takes turn
 * 
 * @return void
 */
void ai_turn( creature_t *creature_p );

#endif