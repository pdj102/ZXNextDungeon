/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Manage an objects list of objects

 ***************************************************/

#ifndef OBJECT_LIST_H 
    #define OBJECT_LIST_H 

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
 * Add an object to the object's list
 * 
 * Object must not belong to another list!
 *
 * @param *obj_p                potiner to object to add
 * @param *container_obj_p      pointer to container object
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t object_list_add(object_t* obj_p, object_t* container_obj_p);

/**
 * Remove an object from the object's list
 *
 * @param *obj_p                object to remove
 * @param *container_obj_p      pointer to container object 
 * 
 * @return uint8_t  1 success 0 fail
 */
uint8_t object_list_remove(object_t* obj_p, object_t* container_obj_p);

/**
 * Returns the first object in the object's list
 *
 * @param *obj_ptr      pointer to the container object  
 * @return *object_t    pointer to first object or 0 if no objects
 */
object_t *object_list_first(object_t *container_obj_p);

/**
 * Returns the next object in the object list
 * 
 * @param   *obj_ptr    pointer to object previously returned by first() or next()
 * 
 * @return  *obj_ptr    pointer to next object or 0 if no more objects
 */
object_t *object_list_next(object_t *obj_ptr);

#endif