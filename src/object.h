/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game objects

 ***************************************************/

#ifndef OBJECT_H 
    #define OBJECT_H 

#include <inttypes.h>

#include "tilemap.h"

#define MAX_OBJECT  40


/***************************************************
 * types
 ***************************************************/

typedef struct
{
    uint8_t                 free;
    tilemap_tile_t          tilemap_tile;
    uint8_t                 x;
    uint8_t                 y;
    uint8_t                 blocking;           /**< 1 if the object is blocking 0 if non-blocking */   
    
} object_t;


/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Initialises the object data structure. Must be called before using Object 
 * 
 * @return void
 */
void object_init();

/**
 * Move object to position x, y if not blocked
 * 
 * @return void
 */
void object_move(object_t *obj, uint8_t x, uint8_t y);

 void object_test();

 uint8_t blocked(uint8_t dungeon_x, uint8_t dungeon_y);

/**
 * Draws all the objects to the graphics tile map
 * 
 * @return void
 */
void object_drawall();

#endif