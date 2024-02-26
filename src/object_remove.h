/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - remove 

 ***************************************************/

#ifndef OBJECT_REMOVE_H 
    #define OBJECT_REMOVE_H 

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
 * Remove object from map
 *
 * @param *obj pointer to object to move
 * 
 */
void object_remove(object_t *obj_p);

#endif