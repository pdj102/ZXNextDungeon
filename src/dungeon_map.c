/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/
#include "dungeon_map.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions
#include <inttypes.h>
#include <stdio.h> 

#include "tilemap.h"

#define DUNGEON_MAP_WIDTH   40
#define DUNGEON_MAP_HEIGHT  40

/***************************************************
 * types
 ***************************************************/
typedef struct
{
    uint8_t tile;
    uint8_t passable;
} dungeon_tile_t;

/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * variables
 ***************************************************/
dungeon_tile_t dungeon_tiles[] =
{
    {1, 1},     // DUNGEON_TILE_FLOOR
    {2, 0}      // DUNGEON_TILE_WALL
};

// dungeon map [x][y] [0][0] top left
dungeon_tile_t dungeon_map[DUNGEON_MAP_WIDTH][DUNGEON_MAP_HEIGHT];

// window is the moveable area within the dungeon selected for display
uint8_t window_y = 0;
uint8_t window_x = 0;
uint8_t window_h = 30;
uint8_t window_w = 20;

/***************************************************
 * functions
 ***************************************************/

void dungeon_map_scroll(int8_t dx, int8_t dy )
{
    // TO DO check bounds
    window_y += dy;
    window_x += dx;
}

void fill(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t dungeon_w, uint8_t dungeon_h, uint8_t tile)
{
    // TODO check bounds
    for (uint8_t y = dungeon_y; y < dungeon_h+dungeon_y; y++ ) {
        for (uint8_t x = dungeon_x; x < dungeon_w+dungeon_x; x++)
            dungeon_map[x][y] = dungeon_tiles[tile];
    }
}

void dungeon_map_init()
{
    fill(0, 0, DUNGEON_MAP_WIDTH, DUNGEON_MAP_HEIGHT, DUNGEON_TILE_WALL);
    fill(2, 2, 7, 5, DUNGEON_TILE_FLOOR);
    fill(10, 10, 4, 5, DUNGEON_TILE_FLOOR);

    fill(9, 4, 3, 1, DUNGEON_TILE_FLOOR);
    fill(12, 4, 1, 6, DUNGEON_TILE_FLOOR);    
}

void dungeon_map_print()
{
    // NB window_y + h and window_x + w must not go beyond map edge
    uint8_t dungeon_y = window_y;
    uint8_t dungeon_x = window_x;

    for (uint8_t screen_y = 0; screen_y < window_h ; screen_y++) {
        for (uint8_t screen_x = 0; screen_x < window_w; screen_x++) {
            tilemap_set_tile(screen_x, screen_y, dungeon_map[dungeon_x][dungeon_y].tile);
            dungeon_x++;
        }
        dungeon_x = window_x;
        dungeon_y++;
    }
}

void dungeon_map_print_tile(uint8_t dungeon_x, uint8_t dungeon_y)
{
    // check tile is within viewable area
    if ( (dungeon_y >= window_y && dungeon_y < window_y + window_h) && (dungeon_x >= window_x && dungeon_x < window_x+window_w) )
    {
        uint8_t screen_x = dungeon_x - window_x;
        uint8_t screen_y = dungeon_y - window_y;

        tilemap_set_tile(screen_x, screen_y, dungeon_map[dungeon_x][dungeon_y].tile);
    }
}

void dungeon_map_print_entity(uint8_t x, uint8_t y, uint8_t tile)
{
    // check tile is within viewable area
    if ( (y >= window_y && y < window_y + window_h) && (x >= window_x && x < window_x+window_w) )
    {
        x = x - window_x;
        y = y - window_y;

        tilemap_set_tile(x, y, tile);
    }
}

uint8_t dungeon_map_passable(uint8_t x, uint8_t y) 
{
    return dungeon_map[x][y].passable;
}
