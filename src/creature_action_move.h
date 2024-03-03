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
 * @brief Attempt to move in direction
 * 
 * @param creature_p    creature_t
 * @param d             direction_t
 *
 * @return 1 if action successful or 0 failed
 */
uint8_t creature_action_move_dir(creature_t *creature_p, direction_t d);

/**
 * @brief Attempt to move by dx dy
 * 
 * @param creature_p    creature_t
 * @param dx
 * @param dy
 *
 * @return 1 if action successful or 0 failed
 */
uint8_t creature_action_move_by(creature_t *creature_p, int8_t dx, int8_t dy);

/**
 * @brief Move creature to position x, y if not blocked by a dungeon wall or objects
 * 
 * Move the creature to position x, y
 * Creature must already be placed on the map 
 *
 * @param creature_p pointer to creature to move
 * @param x move to dungeon x position
 * @param y move to dungeon y position
 * 
 * @return uint8_t  1 if action successful or 0 failed
 */
uint8_t creature_action_move_to(creature_t *creature_p, uint8_t x, uint8_t y);

#endif