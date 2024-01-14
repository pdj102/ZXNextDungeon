/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - destroy

 ***************************************************/

#ifndef OBJECT_DESTROY_H 
    #define OBJECT_DESTROY_H 

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
 * Is object destroyable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if destroyable or 0 if not
 */
uint8_t object_destroy_is(object_t *obj_p);

/**
 * Destory dungeon map object
 *
 * @param *obj pointer to object to destroy
 * 
 * @return uint8_t 1 will always returns 1
 */
uint8_t object_destroy(object_t *obj_p);


#endif