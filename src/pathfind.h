/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding


 ***************************************************/

#ifndef PATHFIND_H 
    #define PATHFIND_H

#include <inttypes.h>

#include "pathfind_bank.h"

/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

uint8_t pathfind_fast_a_star(uint8_t origin_x, uint8_t origin_y, uint8_t goal_x, uint8_t goal_y);

/**
 * @brief Returns the direction towards the player as determined by the last call to pathfind()
 *
 * @return direction_t
 */
direction_t pathfind_direction(uint8_t x, uint8_t y);

/**
 * @brief Displays the current path based on last call to pathfind*
 * 
 */
void pathfind_print( void );

#endif