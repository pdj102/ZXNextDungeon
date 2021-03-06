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


#define NO_MIRROR   0b00000000
#define NO_ROTATE   0b00000000
#define MIRROR_X    0b00001000
#define MIRROR_Y    0b00000100
#define ROTATE      0b00000010


/***************************************************
 * public types
 ***************************************************/

/**
 * @brief A structure to represent a ZX Next tilemap tile
 * 
 */
typedef struct tilemap_tile {
    uint8_t tile_id;            /**< the id of the tile definition */
    uint8_t tile_attr;          /**< the tile attributes */
} tilemap_tile_t;


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
void tilemap_clear(const tilemap_tile_t *tile);

/**
 * Set tilemap tile
 * @param x     x position
 * @param y     y position     
 * @param tile  tilemap tile
 * @return void
 */
void tilemap_set_tile(uint8_t x, uint8_t y, const tilemap_tile_t *tile);


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
void tilemap_set_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const tilemap_tile_t *tile);

#endif