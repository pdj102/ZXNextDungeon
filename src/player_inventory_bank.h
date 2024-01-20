/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - inventory list and actions

    Code is banked do not call directly

 ***************************************************/

#ifndef PLAYER_INVENTORY_BANK_H 
    #define PLAYER_INVENTORY_BANK_H 

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
 * Player list inventory action
 *
 * @return void
 */
void player_inventory_list_b( void );

/**
 * Select an object of type 'is_a' from inventory
 *
 * @return void
 */
object_t *player_inventory_select_object_is_a_b( object_is_a is_a_p );

#endif