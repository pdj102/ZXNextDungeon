/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - stike

 ***************************************************/

#ifndef OBJECT_STRIKE_H 
    #define OBJECT_STRIKE_H 

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
 * Is object strikeable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if pickupable or 0 if not
 */
uint8_t object_strike_is(object_t *obj_p);

#endif