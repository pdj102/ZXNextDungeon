/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   Coordinate types

 ***************************************************/
#include "coord_type.h"


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/


/***************************************************
 * variables
 ***************************************************/
// [dir][x = 0, y = 1]
int8_t dir_delta[9][2] = {
    {0, 0},      // NO DIR
    {0, -1},    // N
    {1, -1},    // NE
    {1, 0},     // E
    {1, 1},     // SE
    {0, 1},     // S
    {-1, 1},    // SW
    {-1, 0},    // W
    {-1, -1}    // NW
};

/***************************************************
 * functions
 ***************************************************/

