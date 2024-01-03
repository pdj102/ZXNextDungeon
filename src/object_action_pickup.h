/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - pickup

 ***************************************************/

#ifndef OBJECT_ACTION_PICKUP_H 
    #define OBJECT_ACTION_PICKUP_H 

#include <inttypes.h>

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
uint8_t object_action_is_pickup(object_t *obj);

/**
 * Pickup object
 *
 * @param *obj pointer to object to pickup
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_action_pickup(object_t *obj_topickup, object_t *obj_container);

/**
 * Return first pickupable object at dungeon x, y
 *
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return *object_t pointer to first pickupable object or 0 if no pickable object
 */
object_t *object_action_pickup_find_first_at(uint8_t x, uint8_t y);

/**
 * Return next pickupable object at dungeon x, y
 *
 * @param *object_t pointer to previous object 
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return *object_t pointer to next pickupable object or 0 if no pickable object
 */
object_t *object_action_pickup_find_next_at(object_t *obj_ptr, uint8_t x, uint8_t y);

#endif