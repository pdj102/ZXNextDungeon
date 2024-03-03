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
uint8_t object_close_is(const object_t *obj_p);

/**
 * Close object if closeable
 *
 * @param *obj pointer to object to close
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_close(object_t *obj_p);


#endif