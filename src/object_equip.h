/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - equip

 ***************************************************/

#ifndef OBJECT_EQUIP_H 
    #define OBJECT_EQUIP_H 

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
 * Is object equipable? 
 *
 * @param *obj_p    pointer to object to check
 * 
 * @return uint8_t  1 if equipable or 0 if not
 */
uint8_t object_equip_is(const object_t *obj_p);


#endif