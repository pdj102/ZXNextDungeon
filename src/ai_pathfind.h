/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

    AI pathfinder

 ***************************************************/

#ifndef AI_PATHFIND_H 
    #define AI_PATHFIND_H 

#include <inttypes.h>

#include "coord_type.h"



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
void ai_pathfind(uint8_t x, uint8_t y);

/**
 * @brief Returns the direction towards the player as determined by the last call to ai_pathfind()
 *
 * @return direction_t
 */
direction_t ai_pathfind_direction_to_player(const coord_t *coord);


void print_path();

#endif