/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - drop

 ***************************************************/

#ifndef OBJECT_DROP_H 
    #define OBJECT_DROP_H 

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
 * Is object dropable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if dropable or 0 if not
 */
uint8_t oobject_drop_is(object_t *obj);

/**
 * Drop object
 *
 * @param *obj_todrop           object to drop
 * @param *obj_container_ptr    container object
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_drop(object_t *obj_todrop, object_t *obj_container_ptr);

/**
 * Drop all objects
 *
 * @param *obj_container_ptr    container object
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_drop_all(object_t *obj_container_ptr);

/**
 * Return an object's first dropable object 
 *
 * @param *obj pointer to object 
 * 
 * @return *object_t pointer to first dropable object or 0 if no dropable object
 */
object_t *object_drop_find_first(object_t *obj_container_ptr);

/**
 * Return next dropable object in list
 *
 * @param *object_t pointer to previous object 
 * 
 * @return *object_t pointer to next dropable object or 0 if no dropable object
 */
object_t *object_drop_find_next(object_t *obj_ptr);

#endif