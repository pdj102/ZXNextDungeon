/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   Player inventory

 ***************************************************/
#include "player_inventory.h"

#include <arch/zxn.h>           // ZX Spectrum Next architecture specfic functions

#include "player_inventory_bank.h"
#include "entity_item.h"
#include "entity_creature.h"


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/


/***************************************************
 * variables
 ***************************************************/
entity_item_t *player_equip_body;
entity_item_t *player_equip_melee;
entity_item_t *player_equip_range;
entity_item_t *player_equip_shield;
entity_item_t *player_equip_left_finger;
entity_item_t *player_equip_right_finger;
entity_item_t *player_equip_head;

/***************************************************
 * functions
 ***************************************************/

void player_inventory_wear(creature_t *creature_ptr)
{
    /* Map Player Inventory (bank 20) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 20);  
    /* Call banked code */
    player_inventory_wear_b(creature_ptr); 
}

void player_inventory_takeoff(creature_t *creature_ptr)
{
    /* Map Player Inventory (bank 20) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 20);  
    /* Call banked code */
    player_inventory_takeoff_b(creature_ptr); 
}

void player_inventory_display(creature_t *creature_ptr)
{
    /* Map Player Inventory (bank 20) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 20);
    /* Call banked code */    
    player_inventory_display_b(creature_ptr); 
}

void player_inventory_drop(creature_t *creature_ptr)
{
    /* Map Player Inventory (bank 20) into ZX Spectrum 8k MMU slot 6 */
    ZXN_WRITE_REG(0x56, 20);
    /* Call banked code */    
    player_inventory_drop_b(creature_ptr);
}

