/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

    Coordinate types

 ***************************************************/

#ifndef COORD_TYPE_H 
    #define COORD_TYPE_H 

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

extern int8_t dir_delta[9][2];



/***************************************************
 * function prototypes
 ***************************************************/

#endif