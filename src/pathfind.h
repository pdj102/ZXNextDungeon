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

/**
 * @brief A* path. Path information is stored in the specified memory page
 * @param origin_x 
 * @param origin_y
 * @param goal_x
 * @param goal_y
 * @param mem_page  memory page that holds the calcualted path
 * @param flags     terain flags that block the path e.g. walls are DGN_FLAG_BLK_ALL | DGN_FLAG_WALL
 * @return 1 if path if found to goal or 0
 */
uint8_t pathfind_fast_a_star(uint8_t origin_x, uint8_t origin_y, uint8_t goal_x, uint8_t goal_y, uint8_t mem_page, uint8_t flags);

/**
 * @brief Returns the direction towards the player as determined by the last call to pathfind()
 *
 * @return direction_t
 */
direction_t pathfind_direction(uint8_t x, uint8_t y, uint8_t mem_page);

/**
 * @brief Displays the current path based on last call to pathfind*
 * 
 */
void pathfind_print( uint8_t mem_page );

#endif