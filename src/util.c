/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Useful utils

 ***************************************************/

#include "util.h"

#include <stdint.h>

#include "globaldata_defines.h"


/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/


/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

uint8_t util_distance_manhattan(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2)
{
    uint8_t x = x1 > x2 ? x1 - x2 : x2 - x1;
    uint8_t y  = y1 > y2 ? y1 - y2 : y2 - y1;

    return x + y;
}

void util_return_area_xy_r(uint8_t x, uint8_t y, uint8_t r, uint8_t *x1, uint8_t *y1, uint8_t *x2, uint8_t *y2)
{   
    // clamp to dungeon size
    *x1 = ( x < r) ? 0 : x - r;                                                  // x1 minimum 0
    *y1 = ( y < r) ? 0 : y - r;                                                  // y1 minimum 0 
    *x2 = ( x > DUNGEONMAP_WIDTH - 1 - r ) ? DUNGEONMAP_WIDTH - 1 : x + r;       // x2 maximum is DUNGEON_WIDTH - 1
    *y2 = ( y > DUNGEONMAP_HEIGHT - 1 - r ) ? DUNGEONMAP_HEIGHT - 1 : y + r;     // y2 maximum is DUNGEON_HEIGHT - 1
}