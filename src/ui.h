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
 * @brief display items at location type
 * 
 * @param entity_location_t location
 * @return number of items in inventory
 */
uint8_t ui_display_items(entity_location_t location);

/**
 * @brief ask player to select item up to letter A + max or press ' ' to cancel
 * 
 * @param uint8_t max item
 * @return 0 = invalid selection or cancel, 1 = A,  2 = B etc
 */
uint8_t ui_select_item(uint8_t max);

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