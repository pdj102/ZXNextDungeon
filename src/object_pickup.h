/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - pickup

 ***************************************************/

#ifndef OBJECT_PICKUP_H 
    #define OBJECT_PICKUP_H 

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
 * Is object pickupable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if pickupable or 0 if not
 */
uint8_t object_pickup_is(object_t *obj);

/**
 * Pickup object
 *
 * @param *obj pointer to object to pickup
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_pickup(object_t *obj_topickup, object_t *obj_container);

#endif