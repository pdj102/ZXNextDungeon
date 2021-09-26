/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Manages ZX Next tilemap

 ***************************************************/

#ifndef TILEMAP_H 
    #define TILEMAP_H 

#include <inttypes.h>

#define TILE_MAP_WIDTH  40
#define TILE_MAP_HEIGHT 32

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
 */ 
void tilemap_init();

/**
 * Clear the whole tilemap to tile
 * @param tile  tile pattern number
 * @return void
 */
void tilemap_clear(uint8_t tile);

/**
 * Set tilemap tile
 * @param x     x position
 * @param y     y position     
 * @param tile  tile pattern number
 * @param tile_attr tile attributes
 * @return void
 */
void tilemap_set_tile(uint8_t x, uint8_t y, uint8_t tile, uint8_t tile_attr);

/**
 * Set tilemap rectangle area to tile
 * @param x     x position
 * @param y     y position
 * @param w     width
 * @param h     height  
 * @param tile  tile pattern number
 * @param tile_attr tile attributes 
 * @return void
 */
void tilemap_set_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t tile, uint8_t tile_attr);

#endif