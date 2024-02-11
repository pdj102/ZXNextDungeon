/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Pathfinding - general utils

    Code is banked do not call directly

 ***************************************************/

#ifndef PATHFIND_BANK_H 
    #define PATHFIND_BANK_H 

#include <inttypes.h>

#include "globaldata_defines.h"

#include "util.h"

/***************************************************
 * types
 ***************************************************/

typedef struct path_s
{
    uint8_t     total_cost;
    uint8_t     cost_so_far;
    direction_t reached_from;
} path_t;

/***************************************************
 * variable declarations
 ***************************************************/
// variables are defined in pathfind_data.asm
extern path_t reached[DUNGEONMAP_WIDTH][DUNGEONMAP_HEIGHT];

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * @brief returns direction from x,y based on last call to pathfind*
 * 
 * @param x 
 * @param y 
 * @return * direction_t 
 */
direction_t pathfind_direction_b(uint8_t x, uint8_t y);

/**
 * @brief marks x,y as reached from direction
 * 
 * @param coord 
 * @param direction_from
 * @param total_cost        cost so far plus reaminging distance to goal. Must be 1 or higher
 * @param cost_so_far       cost of path so far from start
 */
void pathfind_mark_reached_b(coord_t *coord, direction_t direction_from, uint8_t total_cost, uint8_t cost_so_far);

/**
 * @brief returns true if x, y reached 
 * 
 * @param coord 
 * @return uint8_t 
 */
uint8_t pathfind_is_reached_b(coord_t *coord);

/**
 * @brief displays the current path calaculated by the last call to path_find*
 * 
 */
void pathfind_print_b( void );

#endif