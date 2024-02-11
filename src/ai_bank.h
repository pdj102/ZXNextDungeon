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

/**
 * Returns true if creature is an enemy
 * 
 * @return void
 */
uint8_t ai_is_enemy_b(creature_t *attacker_p, creature_t *target_p);

/**
 * @brief calculate manhatten distance
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 * @return uint8_t manhatten distance
 */
uint8_t util_distance_manhattan(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2);

#endif