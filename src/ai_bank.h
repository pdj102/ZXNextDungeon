/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The ai code

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_BANK_H 
    #define AI_BANK_H 

#include "ai.h"

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
void ai_turn_b( ai_t *ai_p );

/**
 * Notify AI of attack by another creature
 * 
 * @return void
 */
void ai_is_attacked_b( ai_t *ai_p, creature_t *attacker_p);

/**
 * Returns true if creature is an enemy
 * 
 * @return void
 */
uint8_t ai_is_enemy_b( ai_t *ai_p, creature_t *target_p);

/**
 * Returns base ai state of AI for object subtype
 * 
 * @return ai_state_t
 */
ai_state_t ai_base_state_b(object_subtype_e subtype);

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