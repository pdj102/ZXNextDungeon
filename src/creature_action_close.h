/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - close

    Creature attempts a close an object

 ***************************************************/

#ifndef CREATURE_ACTION_CLOSE_H 
    #define CREATURE_ACTION_CLOSE_H 

#include <stdint.h>

#include "creature.h"

#include "util.h"

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
 * Attempt close
 * 
 * @param attacker_p    creature_t
 * @param d             direction_t
 *
 * @return object_t if action successful or 0 failed
 */
object_t *creature_action_close_dir(creature_t *creature_p, direction_t d);

/**
 * Attempt close
 * 
 * @param attacker_p    creature_t
 * @param dx            dx
 * @param dy            dy
 *
 * @return object_t if action successful or 0 failed
 */
object_t *creature_action_close_d(creature_t *creature_p, int8_t dx, int8_t dy);


#endif