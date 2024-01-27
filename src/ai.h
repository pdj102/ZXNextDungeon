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
 * Ai takes turn
 * 
 * @return void
 */
void ai_turn( creature_t *creature_p );

/**
 * Notify AI of attack by another creature
 * 
 * @return void
 */
void ai_is_attacked(creature_t *target_p, creature_t *attacker_p);

#endif