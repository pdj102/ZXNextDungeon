/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Useful utils

 ***************************************************/

#ifndef UTIL_H 
    #define UTIL_H 

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


/***************************************************
 * variable declarations
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * @brief returns manhattan distance
 * 
 */
uint8_t util_distance_manhattan(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2);

#endif