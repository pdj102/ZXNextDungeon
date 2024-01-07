/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - close

 ***************************************************/

#ifndef OBJECT_CREATE_H 
    #define OBJECT_CREATE__H 

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
 * Create an  object of type subtype at xm y.  
 *
 * @param subtype object subtype to create
 * @param x dungeon x position
 * @param y dungeon y position
 * @return pointer to created object or NULL on failed to create
 */
object_t* object_create(object_subtype_e subtype, uint8_t x, uint8_t y);


#endif