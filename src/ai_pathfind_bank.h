/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI pathfinding

    Code is banked do not call directly

 ***************************************************/

#ifndef AI_PATHFIND_BANK_H 
    #define AI_PATHFIND_BANK_H 

#include <inttypes.h>

/***************************************************
 * types
 ***************************************************/
typedef enum direction_e {NO_DIR, N, NE, E, SE, S, SW, W, NW} direction_t;

typedef struct
{
    uint8_t x;
    uint8_t y;
} coord_t;

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
void ai_pathfind_b(uint8_t x, uint8_t y);

/**
 * @brief Returns the direction towards the player as determined by the last call to ai_pathfind()
 *
 * @return direction_t
 */
direction_t ai_pathfind_direction_to_player_b(uint8_t x, uint8_t y);

void ai_pathfind_print_b( void );

#endif