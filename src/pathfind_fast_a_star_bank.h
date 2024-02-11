/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Pathfinding - fast a star

    Code is banked do not call directly

 ***************************************************/

#ifndef PATHFIND_FAST_A_STAR_BANK_H 
    #define PATHFIND_FAST_A_STAR_BANK_H 

#include <inttypes.h>

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
 * @brief Calculates the path to goal using fast a star search
 *
 * @return void
 */
uint8_t pathfind_fast_a_star_b(uint8_t origin_x, uint8_t origin_y, uint8_t goal_x, uint8_t goal_y);

#endif