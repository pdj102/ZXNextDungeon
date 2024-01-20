/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - equipment list and actions

    Code is banked do not call directly

 ***************************************************/

#ifndef PLAYER_EQUIPMENT_BANK_H 
    #define PLAYER_EQUIPMENT_BANK_H 

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
 * Player list equipment action
 *
 * @return void
 */
void player_equipment_list_b( void );

/**
 * Select an equipped object
 *
 * @return void
 */
object_t *player_equipment_select_object( void );

#endif