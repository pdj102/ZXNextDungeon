/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - step on

 ***************************************************/

#ifndef OBJECT_ACTION_STEPON_H 
    #define OBJECT_ACTION_STEPON_H 

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
 * Is object triggered by being stepped on? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if triggered by stepping on or 0 if not
 */
uint8_t object_action_is_stepon(object_t *obj);

/**
 * Step on object
 *
 * @param *obj_p           object stepped on
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_action_stepon(object_t *obj_p);

/**
 * Trigger all stepped on objects at dungeon x, y
 *
 * @param x dungeon x position
 * @param y dungeon y position
 */
void *object_action_stepon_all(uint8_t x, uint8_t y);


#endif