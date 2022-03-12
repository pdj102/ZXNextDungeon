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
 * @brief Displays the inventory UI
 * 
 * @param *creature_ptr  pointer to creature
 * @return void
 */
void player_inventory_display_b(creature_t *creature_ptr);

/**
 * @brief Clears the right hand display area
 * 
 * @return void
 */
void player_inventory_blank_display_b();


void player_inventory_wear_b(creature_t *creature_ptr);
void wear_b(uint8_t item_num);

#endif