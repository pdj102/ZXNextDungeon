/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - open

 ***************************************************/

#ifndef OBJECT_ACTION_OPEN_H 
    #define OBJECT_ACTION_OPEN_H 

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
 * Is object openable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if openable or 0 if not
 */
uint8_t object_action_move_is_openable(object_t *obj);

/**
 * Open object if openable
 *
 * @param *obj pointer to object to open
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_action_open(object_t *obj);

/**
 * Return first openable object at dungeon x, y
 *
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return *object_t pointer to first openable object or 0 if no openable object
 */
object_t *object_action_open_findat(uint8_t x, uint8_t y);

#endif