/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game object action - move

 ***************************************************/

#ifndef OBJECT_MOVE_H 
    #define OBJECT_MOVE_H 

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
 * Is object movable 
 *
 * @param *obj pointer to object to check
 * 
 * @return uint8_t  1 if movable or 0 if not
 */
uint8_t object_move_is(object_t *obj);

/**
 * Move object to position x, y if not blocked by a dungeon wall or objects
 * 
 * Use object_move_place to place a new object in the dungeon
 *
 * @param *obj pointer to object to move
 * @param x move to dungeon x position
 * @param y move to dungeon y position
 * 
 * @return uint8_t  1 if action successful or 0 failed
 */
uint8_t object_move_to(object_t *obj_p, uint8_t x, uint8_t y);

/**
 * Move object by delta x, y if not blocked by a dungeon wall or objects
 * 
 * @return uint8_t  1 if action successful or 0 failed
 */
uint8_t object_move_by(object_t *obj, int8_t dx, int8_t dy);

/**
 * Tests if a location is blocked by a dungeon wall or objects
 * 
 * @return 1 if blocked 0 if not blocked
 */
uint8_t object_move_isblocked(uint8_t dungeon_x, uint8_t dungeon_y);

#endif