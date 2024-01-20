/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - takeoff

 ***************************************************/

#ifndef OBJECT_TAKEOFF_H 
    #define OBJECT_TAKEOFF_H 

#include <stdint.h>

#include "object.h"

#include "creature.h"

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
 * Is object takeoffable? 
 *
 * @param *obj_p    pointer to object to check
 * 
 * @return uint8_t  1 if takeoffable or 0 if not
 */
uint8_t object_takeoff_is(const object_t *obj_p);


#endif