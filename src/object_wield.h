/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - wield

 ***************************************************/

#ifndef OBJECT_WIELD_H 
    #define OBJECT_WIELD_H 

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
 * Is object wieldable? 
 *
 * @param *obj_p    pointer to object to check
 * 
 * @return uint8_t  1 if wieldable or 0 if not
 */
uint8_t object_wield_is(const object_t *obj_p);


#endif