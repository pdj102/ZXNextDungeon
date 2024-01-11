/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon map

 ***************************************************/

#ifndef DUNGEONMAP_H 
    #define DUNGEONMAP_H 

#include <stdint.h>

#include "tilemap.h"


#define DUNGEONMAP_WIDTH   40
#define DUNGEONMAP_HEIGHT  40

#define FLAG_BLOCKIKNG 1 << 0



/***************************************************
 * types
 ***************************************************/

typedef enum dungeonmap_tile_type {FLOOR, BRICKWALL, SOLIDWALL} dungeonmap_tile_type_e;

// Dungeon map tile 
typedef struct
{
    tilemap_tile_t          tilemap_tile;
    dungeonmap_tile_type_e  tile;
    uint8_t                 flags;
} dungeonmap_tile_t;

// Dungeon map data structure
typedef struct 
{
    dungeonmap_tile_t map[DUNGEONMAP_WIDTH][DUNGEONMAP_HEIGHT];

    // position of scrollable viewpoint within dungeon map  
    uint8_t window_y;
    uint8_t window_x;
    uint8_t window_h;
    uint8_t window_w;
} dungeonmap_t;


/***************************************************
 * variable declarations
 ***************************************************/

// extern dungeonmap_t *const dungeonmap;


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the dungeonmap. Must be called before using Dungeon Map. 
 * 
 * @return void
 */
void dungeonmap_init( void );

/**
 * Set the dungeonmap scrollable view window position. 
 * 
 * @return void
 */
void dungeonmap_setwindow(uint8_t y, uint8_t x, uint8_t h, uint8_t w);

/**
 * Move dungeon window by dx dy
 * 
 * @param dx delta x
 * @param dy delta y
 * @return void
 * 
 */
void dungeonmap_scroll(int8_t dx, int8_t dy );

/**
 * Draws the dungeon map to the graphics tilemap
 * TODO bounds checking - window_y + h and window_x + w must not go beyond map edge
 * 
 * @return void
 */
void dungeonmap_draw( void );

/**
 * Draw a single tile to the graphics tilemap at dungeon position x, y
 * Use to draw objects onto the dungeon map
 * 
 * @param dungeon_x x position
 * @param dungeon_y y position
 * @param tile      tile to draw
 * @return void
 */
void dungeonmap_draw_single_tile(uint8_t dungeon_x, uint8_t dungeon_y, const tilemap_tile_t *tile);

/**
 * Set the tile at dungeon position x, y
 * 
 * @param dungeon_x x position
 * @param dungeon_y y position
 * @param tile_type type of tile to set
 * @return void
 */
void dungeonmap_set_tile(uint8_t dungeon_x, uint8_t dungeon_y, dungeonmap_tile_type_e tile_type);


/**
 * Move dungeon window by dx dy
 * 
 * @param dx delta x
 * @param dy delta y
 * @return void
 */
void dungeonmap_scroll(int8_t dx, int8_t dy);

/**
 * Returns 1 if dungeon map tile is blocked else 0
 * 
 * @param dungeon_x x position
 * @param dungeon_y y position
 * @return 1 passable 0 impassable
 */
uint8_t dungeonmap_tile_is_blocked(uint8_t dungeon_x, uint8_t dungeon_y);



#endif