/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - move action

    Code is banked do not call directly

 ***************************************************/

#ifndef PLAYER_MOVE_BANK_H 
    #define PLAYER_MOVE_BANK_H 

#include "object.h"
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
 * Player move action
 *
 * @return void
 */
void player_move_b(direction_t d);

#endif