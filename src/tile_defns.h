/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tile definitions

 ***************************************************/

#ifndef TILE_DEFNS_H 
    #define TILE_DEFNS_H 

#define TILE_COLOURS    0
#define TILE_FLOOR      1
#define TILE_WALL       2
#define TILE_BOX        3
#define TILE_PLAYER     4
#define TILE_SNAKE      5

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
 * Initialise tile definitions. Must be called before using tilemap
 * 
 * @return void
 */
void tile_defns_init();


#endif