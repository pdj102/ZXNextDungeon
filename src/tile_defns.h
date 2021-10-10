/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tile definitions

 ***************************************************/

#ifndef TILE_DEFNS_H 
    #define TILE_DEFNS_H 

#define TILE_0_0        0
#define TILE_0_1        1
#define TILE_0_2        2
#define TILE_0_3        3

#define TILE_WALL_1     4
#define TILE_WALL_2     5
#define TILE_WALL_3     6
#define TILE_WALL_4     7

#define TILE_FLOOR_1    8
#define TILE_CEILING    9
#define TILE_FLOOR_2    10
#define TILE_2_3        11

#define TILE_3_0        12
#define TILE_3_1        13  //top blue line
#define TILE_3_2        14
#define TILE_3_3        15  //bottom blue line

#define TILE_4_0        16
#define TILE_4_1        17  // right blue line
#define TILE_4_2        18
#define TILE_4_3        19  // left blue line

#define TILE_5_0        20  // inner bottom right corner
#define TILE_5_1        21
#define TILE_5_2        22
#define TILE_5_3        23

#define TILE_6_0        24 // bottom left corner
#define TILE_6_1        25 // top right corner
#define TILE_6_2        26 // left line
#define TILE_6_3        27 // top left corner

#define TILE_7_0        28  // player palette offset 1
#define TILE_7_1        29
#define TILE_7_2        30
#define TILE_7_3        31

#define TILE_8_0        32  // enemy palette offset 2
#define TILE_8_1        33
#define TILE_8_2        34
#define TILE_8_3        35

#define TILE_POTION     36  // palete 3 for red 4 for blue
#define TILE_9_1        37
#define TILE_RING       38
#define TILE_9_3        39

#define TILE_PLAYER     28
#define TILE_SNAKE      32

#define TILE_TRANS      0      


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