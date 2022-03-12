/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/

#ifndef DUNGEON_MAP_H 
    #define DUNGEON_MAP_H 

#include <inttypes.h>

#include "tilemap.h"


#define DUNGEON_MAP_WIDTH   40
#define DUNGEON_MAP_HEIGHT  40


/***************************************************
 * types
 ***************************************************/

typedef enum tile_type {FLOOR, WALL, CEILING} tile_type_e;

typedef struct
{
    tilemap_tile_t      tilemap_tile;
    tile_type_e         tile;
} dungeon_tile_t;


/***************************************************
 * variable declarations
 ***************************************************/

extern dungeon_tile_t dungeon_map[DUNGEON_MAP_WIDTH][DUNGEON_MAP_HEIGHT];


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the dungeon_map. Must be called before using Dungeon Map. 
 * 
 * @return void
 */
void dungeon_map_init();

/**
 * Prints the dungeon map to the tilemap
 * TODO bounds checking - window_y + h and window_x + w must not go beyond map edge
 * 
 * @return void
 */
void dungeon_map_draw();

/**
 * Redraw a single dungeon tile to the tilemap
 * 
 * @param dungeon_x x position
 * @param dungeon_y y position
 * @return void
 */
void dungeon_map_draw_tile(uint8_t dungeon_x, uint8_t dungeon_y);

/**
 * Draw a single tilemap tile at dungeon x, y to the tilemap 
 * 
 * @param dungeon_x x position
 * @param dungeon_y y position
 * @param tile tile_map tile
 * @return void
 */
void dungeon_map_draw_entity(uint8_t dungeon_x, uint8_t dungeon_y, const tilemap_tile_t *tile);

/**
 * Move dungeon window by dx dy
 * 
 * @param dx delta x
 * @param dy delta y
 * @return void
 */
void dungeon_map_scroll(int8_t dx, int8_t dy);

/**
 * Returns 1 if dungeon map tile is floor else 0
 * 
 * @param dungeon_x x position
 * @param dungeon_y y position
 * @return 1 passable 0 impassable
 */
uint8_t dungeon_map_tile_passable(uint8_t dungeon_x, uint8_t dungeon_y);

/**
 * Is dungeon map x, y blocked?
 * 
 * @param dungeon_x x position
 * @param dungeon_y y position
 * @return 1 blocked 0 not blocked
 */
uint8_t dungeon_map_is_blocked(uint8_t dungeon_x, uint8_t dungeon_y);

#endif