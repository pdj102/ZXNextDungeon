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
void player_init_b(creature_t *creature_p);

/**
 * Player takes turn
 * 
 * @return void
 */
void player_turn_b( void );

uint8_t get_dir_or_cancel_b(int8_t *dx, int8_t *dy);

object_t *select_object_from_inventory_b( object_is_a is_a_p );

#endif