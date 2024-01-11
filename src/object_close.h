/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - close

 ***************************************************/

#ifndef OBJECT_CLOSE_H 
    #define OBJECT_CLOSE_H 

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
 * Is object closeable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if closeable or 0 if not
 */
uint8_t object_close_is(object_t *obj);

/**
 * Close object if closeable
 *
 * @param *obj pointer to object to close
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_close(object_t *obj);

/**
 * Return first closeable object at dungeon x, y
 *
 * @param x dungeon x position
 * @param y dungeon y position
 * 
 * @return *object_t pointer to first closeable object or 0 if no closeable object
 */
object_t *object_close_findat(uint8_t x, uint8_t y);

#endif