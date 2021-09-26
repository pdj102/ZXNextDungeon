/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/

#ifndef DUNGEON_MAP_H 
    #define DUNGEON_MAP_H 

#include <inttypes.h>

#define DUNGEON_TILE_FLOOR_1    0
#define DUNGEON_TILE_WALL_1     1
#define DUNGEON_TILE_CEILING    2



/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/

extern uint8_t dungeon_map_width;
extern uint8_t dungeon_map_height;


/***************************************************
 * function prototypes
 ***************************************************/

// initialises the dungeon_map. Must be called before use. 
void dungeon_map_init();

// Prints the dungeon map to the ULA screen
void dungeon_map_draw();

// redraw a single dungeon tile 
void dungeon_map_draw_tile(uint8_t dungeon_x, uint8_t dungeon_y);

// draw an entity at y, x 
void dungeon_map_draw_entity(uint8_t dungeon_x, uint8_t dungeon_y, uint8_t tile, uint8_t tile_attr);

// scroll dungeon map 
void dungeon_map_scroll(int8_t dx, int8_t dy);

//  return 
//      1   passable
//      0   not passable
uint8_t dungeon_map_tile_passable(uint8_t dungeon_x, uint8_t dungeon_y);


#endif