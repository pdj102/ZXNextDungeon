/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manages ZX Next tilemap

 ***************************************************/

#ifndef TILEMAP_H 
    #define TILEMAP_H 

#include <inttypes.h>

/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/** 
 * Initialise the tile_map. Must be called before using tile map.
 * @return void
 */ 
void tilemap_init();

/**
 * Set tilemap tile
 * @param x     x position
 * @param y     y position     
 * @param tile  tile pattern number
 * @return void
 */
void tilemap_set_tile(uint8_t x, uint8_t y, uint8_t tile);


#endif