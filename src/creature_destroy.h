/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - destroy

 ***************************************************/

#ifndef CREATURE_DESTROY_H 
    #define CREATURE_DESTROY_H 

#include <stdint.h>

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
 * Is creature destroyable? 
 *
 * @param *creature pointer to creature to check
 * 
 * @return uint8_t  1 if destroyable or 0 if not
 */
uint8_t creature_destroy_is(creature_t *creature_p);

/**
 * Destory creature object
 * 
 * Note - must also destory the creature's object
 *
 * @param *creature_p pointer to creature to destroy
 * 
 * @return uint8_t 1 will always returns 1
 */
uint8_t creature_destroy(creature_t *creature_p);


#endif