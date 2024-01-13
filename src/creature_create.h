/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Create creature

 ***************************************************/

#ifndef CREATURE_CREATE_H 
    #define CREATURE_CREATE_H 

#include <stdint.h>

#include "creature.h"
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
 * Create a creature
 * 
 * Creates a creature based on the provided object. 
 * NB the object specifies the creature type to create
 *
 * @param obj_p* pointer to object
 *
 * @return pointer to created creature or NULL on failed to create
 */
creature_t* creature_create(object_t *obj_p);

#endif