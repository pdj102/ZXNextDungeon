/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief ZXNext tile map

 ***************************************************/

#ifndef TILE_MAP_H 
    #define TILE_MAP_H 

#include <stdint.h>

#define TILE_MAP_WIDTH  40
#define TILE_MAP_HEIGHT 32


#define PALETTE_PURPLE          0b00000000
#define PALETTE_DARK_GREEN      0b00010000
#define PALETTE_ORANGE          0b00100000
#define PALETTE_YELLOW          0b00110000
#define PALETTE_RED             0b01000000
#define PALETTE_BLUE            0b01010000
#define PALETTE_GREEN           0b01100000
#define PALETTE_WHITE           0b01110000
#define MIRROR_X                0b00001000
#define MIRROR_Y                0b00000100
#define ROTATE                  0b00000010

#define TILE_ID_ROCK            0
#define TILE_ID_FLOOR           1
#define TILE_ID_STONEWALL_END   2
#define TILE_ID_STONEWALL       3
#define TILE_ID_BRICKWALL_1     4
#define TILE_ID_BRICKWALL_2     5
#define TILE_ID_BRICKWALL_TORCH 6
#define TILE_ID_BRICKWALL_3     7
#define TILE_ID_POTION          8
#define TILE_ID_LONG_SWORD      9
#define TILE_ID_SHORT_SWORD     10
#define TILE_ID_CLUB            11
#define TILE_ID_SLING           12
#define TILE_ID_ARROW           13
#define TILE_ID_BOW             14
#define TILE_ID_CROSSBOW        15
#define TILE_ID_ARMOUR          16
#define TILE_ID_RING            17
#define TILE_ID_OPENDOOR        18
#define TILE_ID_CLOSEDDOOR      19
#define TILE_ID_CHEST           20
#define TILE_ID_TRAP            21
#define TILE_ID_SNAKE           128
#define TILE_ID_HUMAN           129
#define TILE_ID_PLANT           130


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
 * Initialise tile map. Must be called before using tilemap
 * 
 * @return void
 */
void tilemap_init( void );

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
 * @param tile  tilemap tile
 * @return void
 */
void tilemap_set_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const tilemap_tile_t *tile);

/**
 * Copy tile 
 * @param fx     from x
 * @param fy     from y
 * @param tx     to x
 * @param ty     to y
 *
 * @return void
 */
void tilemap_copy_tile(uint8_t fx, uint8_t fy, uint8_t tx, uint8_t ty);

#endif
