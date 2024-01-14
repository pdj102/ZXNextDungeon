/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - quaff

 ***************************************************/

#ifndef OBJECT_QUAFF_H 
    #define OBJECT_QUAFF_H 

#include <stdint.h>

#include "object.h"

#include "creature.h"

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
 * Is object quaffable? 
 *
 * @param *obj_p    pointer to object to check
 * 
 * @return uint8_t  1 if quaffable or 0 if not
 */
uint8_t object_quaff_is(const object_t *obj_p);

/**
 * Quaff object if quaffable
 *
 * @param *creature_p   pointer to creature 
 * @param *obj_p        pointer to object to quaff
 * 
 * @return uint8_t 1 if action successful or 0 failed
 */
uint8_t object_quaff(creature_t *creature_p, object_t *obj_p);


#endif