/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

    AI 

    Banked code. Do not call directly

 ***************************************************/

#ifndef AI_BANK_H 
    #define AI_BANK_H 

#include "entity_creature.h"



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
 * @brief AI creature takes a turn
 * 
 * @param *creature_ptr  pointer to creature
 * @return void
 */
void ai_turn_b(creature_t *creature_ptr);


#endif