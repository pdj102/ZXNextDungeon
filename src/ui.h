/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief <Module description>

 ***************************************************/

#ifndef UI_H 
    #define UI_H 

#include <inttypes.h>

#include "entity_creature.h"


/***************************************************
 * public types
 ***************************************************/

/***************************************************
 * public variable declarations - extern
 ***************************************************/

/***************************************************
 * public function prototypes
 ***************************************************/

/**
 * @brief display the inventory of the creature
 * 
 * @param creature_ptr display inventory of this creature
 * @return number of items in inventory
 */
uint8_t ui_display_inventory();

/**
 * @brief display the stats of the creature
 * 
 * @param creature_ptr display stats of this creature
 * @return void
 */
void ui_draw_stat_block(const creature_t *creature_ptr);

/**
 * @brief clear the ui
 * 
 * @return void
 */
void ui_clear_display();


#endif