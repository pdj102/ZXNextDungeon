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

/**
 * Return first strikeable object at dungeon x, y
 *
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return *object_t pointer to first strikeable object or 0 if no strikeable object
 */
object_t *object_strike_find_first_at(uint8_t x, uint8_t y);

/**
 * Return next strikeable object at dungeon x, y
 *
 * @param *object_t pointer to previous object 
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return *object_t pointer to next strikeable object or 0 if no strikeable object
 */
object_t *object_strike_find_next_at(object_t *obj_ptr, uint8_t x, uint8_t y);

#endif