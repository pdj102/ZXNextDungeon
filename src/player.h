/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code

 ***************************************************/

#ifndef PLAYER_H 
    #define PLAYER_H 

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
 * Init the player
 *
 * @param obj_ptr pointer to the player object
 * @return void
 */
void player_init(object_t *obj_ptr);

/**
 * Player takes turn
 * 
 * @return void
 */
void player_turn();

#endif