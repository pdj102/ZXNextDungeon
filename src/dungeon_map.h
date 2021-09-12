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

// redrawa  single tile
void dungeon_map_print_tile(uint8_t y, uint8_t x);

//  return 
//      1   passable
//      0   not passable
uint8_t dungeon_map_passable(uint8_t y, uint8_t x);


#endif