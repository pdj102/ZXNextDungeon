/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code

 ***************************************************/

#ifndef PLAYER_H 
    #define PLAYER_H 

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
 * Init the player
 *
 * @param obj_ptr pointer to the player object
 * @return void
 */
void player_init(creature_t *creature_p);

/**
 * Player takes turn
 * 
 * @return void
 */
void player_turn( void );

#endif