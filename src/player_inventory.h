/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

    Player inventory

 ***************************************************/

#ifndef PLAYER_INVENTORY_H 
    #define PLAYER_INVENTORY_H 


#include "entity_creature.h"



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
 * @brief Command displays inventory
 * 
 * @param *creature_ptr  pointer to creature
 * @return void
 */
void player_inventory_display(creature_t *creature_ptr);

/**
 * @brief Command wear/wield item
 * 
 * @return void
 */
void player_inventory_wear(creature_t *creature_ptr);


#endif