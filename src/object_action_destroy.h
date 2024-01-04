/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - destroy

 ***************************************************/

#ifndef OBJECT_ACTION_DESTROY_H 
    #define OBJECT_ACTION_DESTROY_H 

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
 * Is object destroyable? 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if destroyable or 0 if not
 */
uint8_t object_action_is_destroy(object_t *obj);

/**
 * Destory dungeon map object
 *
 * @param *obj pointer to object to destroy
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_action_destroy(object_t *obj_todestroy);


#endif