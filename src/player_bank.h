/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code

    Code is banked do not call directly

 ***************************************************/

#ifndef PLAYER_BANK_H 
    #define PLAYER_BANK_H 

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
 * @brief Init the player
 *
 * @return void
 */
void player_init_b( void );

/**
 * @brief Player takes turn
 * 
 * @return void
 */
void player_turn_b( void );

/**
 * @brief   Get a direction
 * 
 * @return direction_t
 */
direction_t get_dir_or_cancel_b( void );

object_t *select_object_from_inventory_b( object_is_a is_a_p );

#endif