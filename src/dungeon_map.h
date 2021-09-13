/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

 ***************************************************/

#ifndef DUNGEON_MAP_H 
    #define DUNGEON_MAP_H 

#include <inttypes.h>

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
void dungeon_map_print();

// redraw a single dungeon tile 
void dungeon_map_print_tile(uint8_t dy, uint8_t dx);

// draw an entity at y, x 
void dungeon_map_print_entity(uint8_t y, uint8_t x, char c);

// scroll dungeon map 
void dungeon_map_scroll(int8_t dy, int8_t dx );

//  return 
//      1   passable
//      0   not passable
uint8_t dungeon_map_passable(uint8_t y, uint8_t x);


#endif