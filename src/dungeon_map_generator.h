/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

    Dungeon map generator 

 ***************************************************/

#ifndef DUNGEON_MAP_GENERATOR_H 
    #define DUNGEON_MAP_GENERATOR_H 

#include <inttypes.h>

#include "dungeon_map.h"                // dungeon_tile_t
#include "tilemap_tile_defns.h"         // tile definitions e.g. TILE_FLOOR_1
#include "palette.h"                    // palette definitions e.g. PALETTE_DUNGEON



/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/




/***************************************************
 * function prototypes
 ***************************************************/

// generate a dungeon map 
void dungeon_map_generate();

#endif