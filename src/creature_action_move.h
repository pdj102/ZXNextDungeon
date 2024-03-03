/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The creature code - move action

    Code is banked do not call directly

 ***************************************************/

#ifndef CREATURE_ACTION_MOVE_H 
    #define CREATURE_ACTION_MOVE_H 

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
 * Move creature to position x, y if not blocked by a dungeon wall or objects
 *
 * @param creature_p pointer to creature to move
 * @param x move to dungeon x position
 * @param y move to dungeon y position
 * 
 * @return uint8_t  1 if action successful or 0 failed
 */
uint8_t creature_action_move_to(creature_t *creature_p, uint8_t x, uint8_t y);

/**
 * Creature move action
 *
* @return 1 on sucess 0 on fail
 */
uint8_t creature_action_move_by(creature_t *creature_p, int8_t dx, int8_t dy);

/**
 * Creature move action
 *
 * @return void
 */
uint8_t creature_action_move_dir(creature_t *creature_p, direction_t d);

#endif