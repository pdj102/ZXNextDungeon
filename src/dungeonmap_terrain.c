/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon map terrain

 ***************************************************/
#include "dungeonmap_terrain.h"

#include "tilemap.h"

/***************************************************
 * types
 ***************************************************/

/***************************************************
 * function prototypes
 ***************************************************/

/***************************************************
 * private variables - static
 ***************************************************/

/***************************************************
 * global variable definition
 ***************************************************/
const dungeonmap_terrain_t terrain[TERRAIN_MAX] = {
    { {TILE_ID_FLOOR, PALETTE_ORANGE},          DGN_FLAG_FLOOR }, 
    { {TILE_ID_ROCK, PALETTE_ORANGE},           DGN_FLAG_WALL },
    { {TILE_ID_BRICKWALL_1, PALETTE_ORANGE},    DGN_FLAG_WALL },
    { {TILE_ID_STONEWALL, PALETTE_ORANGE},      DGN_FLAG_WALL },
    { {TILE_ID_STONEWALL_END, PALETTE_ORANGE},  DGN_FLAG_WALL }
};

/***************************************************
 * functions
 ***************************************************/

