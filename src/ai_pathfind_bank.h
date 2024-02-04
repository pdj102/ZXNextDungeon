/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding - general utils

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_PATHFIND_BANK_H 
    #define AI_PATHFIND_BANK_H 

#include <inttypes.h>

/***************************************************
 * types
 ***************************************************/
typedef enum direction_e {NO_DIR, N, NE, E, SE, S, SW, W, NW} direction_t;

typedef struct coord_s
{
    uint8_t x;
    uint8_t y;
} coord_t;

typedef struct path_s
{
    uint8_t reached;    
    direction_t reached_from;
} path_t;

/***************************************************
 * variable declarations
 ***************************************************/
// variables are defined in ai_pathfind_data.asm
extern path_t reached[40][40];

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * @brief returns direction from x,y based on last call to ai_pathfind*
 * 
 * @param x 
 * @param y 
 * @return * direction_t 
 */
direction_t ai_pathfind_direction_b(uint8_t x, uint8_t y);

/**
 * @brief marks x,y as reached from direction
 * 
 * @param coord 
 * @param direction_from 
 */
void mark_reached_b(coord_t *coord, direction_t direction_from);

/**
 * @brief returns true if x, y reached 
 * 
 * @param coord 
 * @return uint8_t 
 */
uint8_t is_reached_b(coord_t *coord);

/**
 * @brief displays the current path calaculated by the last call to path_find*
 * 
 */
void ai_pathfind_print_b( void );

#endif