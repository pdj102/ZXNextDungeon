/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

    AI 

 ***************************************************/

#ifndef AI_H 
    #define AI_H 

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
void ai_turn(creature_t *creature_ptr);


#endif