/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tile definitions

 ***************************************************/

#ifndef TILE_DEFNS_H 
    #define TILE_DEFNS_H 

#define TILE_WALL_1     0
#define TILE_WALL_2     1

#define TILE_FLOOR_1    4
#define TILE_CEILING    5
#define TILE_6          6
#define TILE_7          7

#define TILE_8          8
#define TILE_9          9
#define TILE_10         10
#define TILE_11         11

#define TILE_12         12
#define TILE_13         13
#define TILE_14         14
#define TILE_15         15

#define TILE_16         16
#define TILE_17         17
#define TILE_18         18
#define TILE_19         19

#define TILE_20         20
#define TILE_21         21
#define TILE_22         22
#define TILE_23         23

#define TILE_24         24
#define TILE_25         25
#define TILE_26         26
#define TILE_27         27

#define TILE_PLAYER     24
#define TILE_SNAKE      25

#define TILE_COLOURS    0
#define TILE_TRANS      1


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