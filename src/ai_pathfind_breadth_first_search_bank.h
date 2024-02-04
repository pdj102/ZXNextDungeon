/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding - breadth first search

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_PATHFIND_BREADTH_FIRST_SEARCH_BANK_H 
    #define AI_PATHFIND_BREADTH_FIRST_SEARCH_BANK_H 

#include <inttypes.h>

#include "ai_pathfind.h"

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
 * @brief Calculates the path towards the player from every reachable dungeon tile using breadth first search
 *
 * @return void
 */
void ai_pathfind_breadth_first_search_b(uint8_t x, uint8_t y);

/**
 * @brief Returns the direction towards the player as determined by the last call to ai_pathfind()
 *
 * @return direction_t
 */
direction_t ai_pathfind_direction_b(uint8_t x, uint8_t y);

void ai_pathfind_print_b( void );

#endif