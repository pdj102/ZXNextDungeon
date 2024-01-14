/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - open

 ***************************************************/

#ifndef OBJECT_OPEN_H 
    #define OBJECT_OPEN_H 

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
 * Is object openable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if openable or 0 if not
 */
uint8_t object_open_is(object_t *obj);

/**
 * Open object if openable
 *
 * @param *obj pointer to object to open
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_open(object_t *obj);


#endif