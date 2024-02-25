/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Dungeon map terrain

 ***************************************************/

#ifndef DUNGEONMAP_TERRAIN_H 
    #define DUNGEONMAP_TERRAIN_H 

#include <stdint.h>

#include "tilemap.h"

#include "globaldata_defines.h"


/***************************************************
 * types
 ***************************************************/

// TERRAIN flags 
#define DGN_FLAG_BLK_ALL            (uint8_t) 1 << 0      // Blocks everything e.g. dungeon boundary wall
#define DGN_FLAG_WALL               (uint8_t) 1 << 1      // A wall that blocks physical objects
#define DGN_FLAG_FLOOR              (uint8_t) 1 << 2      // A floor that can be walked on 
#define DGN_FLAG_HOLE               (uint8_t) 1 << 3      // A deep hole that can't be walked over
#define DGN_FLAG_WATER              (uint8_t) 1 << 4      // Deep water that can't be walked over
#define DGN_FLAG_BLK_OBJECT         (uint8_t) 1 << 6      // A blocking object such as a closed door
#define DGN_FLAG_OBJECT             (uint8_t) 1 << 7      // Object presence flag

typedef enum dungeonmap_terrain_type_e {TERRAIN_FLOOR, TERRAIN_ROCK, TERRAIN_BRICKWALL, TERRAIN_STONEWALL, TERRAIN_STONEWALL_END, TERRAIN_MAX } dungeonmap_terrain_type_t;

// Terrain
typedef struct dungeonmap_terrain_s
{
    tilemap_tile_t              tilemap_tile;       // Display tilemap tile
    uint8_t                     default_flags;
} dungeonmap_terrain_t;

/***************************************************
 * variable declarations
 ***************************************************/
extern const dungeonmap_terrain_t terrain[];

/***************************************************
 * function prototypes
 ***************************************************/


#endif