/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding


 ***************************************************/

#ifndef AI_PATHFIND_H 
    #define AI_PATHFIND_H

#include <inttypes.h>

#include "ai_pathfind_bank.h"

/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

void ai_pathfind_fast_a_star(uint8_t origin_x, uint8_t origin_y, uint8_t goal_x, uint8_t goal_y);

/**
 * @brief Returns the direction towards the player as determined by the last call to ai_pathfind()
 *
 * @return direction_t
 */
direction_t ai_pathfind_direction(uint8_t x, uint8_t y);

/**
 * @brief Displays the current path based on last call to ai_pathfind*
 * 
 */
void ai_pathfind_print( void );

#endif