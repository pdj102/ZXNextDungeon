/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - place on map

 ***************************************************/

#ifndef OBJECT_PLACE_H 
    #define OBJECT_PLACE_H 

#include <stdint.h>

#include "object.h"

/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/

/**
 * Place object on map at position x, y 
 *
 * @param *obj pointer to object to move
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return uint8_t  1 if action successful or 0 failed
 */
void object_place(object_t *obj_p, uint8_t x, uint8_t y);

#endif