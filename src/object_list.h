/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Lists of objects

 ***************************************************/

#ifndef OBJECT_LIST_H 
    #define OBJECT_LIST_H 

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
 * Add an object to the container object's list
 * 
 * Object must not belong to another list!
 *
 * @param *obj_p                object to add
 * @param *container_obj_p      container object
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t object_list_add(object_t* obj_p, object_t* container_obj_p);

/**
 * Remove an object from the container object's list
 *
 * @param *obj_p                object to remove
 * @param *container_obj_p      container object 
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t object_list_remove(object_t* obj_p, object_t* container_obj_p);

/**
 * Returns the first object in an object's object list
 *
 * @param *obj_ptr      pointer to the container object  
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_list_first(object_t *container_obj_p);

/**
 * Returns the next object in the object list
 * 
 * @return *obj_ptr    pointer to next object or 0 if no more objects
 */
object_t *object_list_next(object_t *obj_ptr);

#endif