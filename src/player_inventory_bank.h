/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson 

    Player inventory

    Banked code. Do not call directly

 ***************************************************/

#ifndef PLAYER_INVENTORY_BANK_H 
    #define PLAYER_INVENTORY_BANK_H 

#include "entity_creature.h"



/***************************************************
 * types
 ***************************************************/

/***************************************************
 * variable declarations
 ***************************************************/

extern creature_t *creature_player_ptr;
extern entity_t *entity_player_ptr;

/***************************************************
 * function prototypes
 ***************************************************/

/**
 * @brief Displays the inventory UI
 * 
 * @param *creature_ptr  pointer to creature
 * @return void
 */
void player_inventory_display_b(creature_t *creature_ptr);

/**
 * @brief Player wear/wield item
 * 
 * @return void
 */
void player_inventory_wear_b(creature_t *creature_ptr);

/**
 * @brief Player take off item
 * 
 * @return void
 */
void player_inventory_takeoff_b(creature_t *creature_ptr);

/**
 * @brief Player drop item
 * 
 * @return void
 */
void player_inventory_drop_b(creature_t *creature_ptr);

#endif