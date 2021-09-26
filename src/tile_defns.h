/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

    Tile definitions

 ***************************************************/

#ifndef TILE_DEFNS_H 
    #define TILE_DEFNS_H 

#define TILE_WALL_1     4
#define TILE_WALL_2     5
#define TILE_WALL_3     6
#define TILE_WALL_4     7

#define TILE_FLOOR_1    8
#define TILE_CEILING    9
#define TILE_FLOOR_2    10
#define TILE_1_4        11

#define TILE_2_1        12
#define TILE_2_2        13
#define TILE_2_3        14
#define TILE_2_4        15

#define TILE_3_1        16
#define TILE_3_2        17
#define TILE_3_3        18
#define TILE_3_4        19

#define TILE_4_1        20
#define TILE_4_2        21
#define TILE_4_3        22
#define TILE_4_4        23

#define TILE_5_1        24
#define TILE_5_2        25
#define TILE_5_3        26
#define TILE_5_4        27

#define TILE_6_1        28
#define TILE_6_2        29
#define TILE_6_3        30
#define TILE_6_4        31

#define TILE_PLAYER     28
#define TILE_SNAKE      28

#define TILE_RING       28
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