/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   Player inventory

   Banked code. Do not call directly

 ***************************************************/
#include "player_inventory_bank.h"

#include <stdio.h>      // NULL
#include <input.h>      //  in_WaitForKey()


#include "entity_item.h"
#include "entity_creature.h"

#include "player.h"

#include "ui.h"

#include "text.h"
#include "messages.h"


#pragma output CRT_ORG_CODE = 0xC000 


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/

extern entity_item_t *player_equip_body;
extern entity_item_t *player_equip_left_hand;
extern entity_item_t *player_equip_right_hand;
extern entity_item_t *player_equip_left_finger;
extern entity_item_t *player_equip_right_finger;
extern entity_item_t *player_equip_head;


/***************************************************
 * Private function prototypes - static
 ***************************************************/

static uint8_t select_item_b(uint8_t max);

static void unequip_b(entity_item_t *item_ptr);

static void equip_ring_b(entity_item_t *item_ptr);

static void calculate_stats_b();

static void apply_affect_mod(entity_item_t *item_ptr);

/***************************************************
 * functions
 ***************************************************/

void player_inventory_wear_b(creature_t *creature_ptr)
{
    uint8_t max;
    uint8_t index;
    uint8_t i = 1;    
    entity_item_t *item_ptr;

    max = ui_display_items(inventory);

    if (max == 0)
    {
        messages_println("NO ITEMS TO EQUIP");
        return;
    }

    messages_println("SELECT ITEM TO EQUIP OR SPACE TO EXIT"); 

    index = ui_select_item(max);

    if (index == 0)
    {       
        return;        
    }

    item_ptr = entity_item_get_nth_at_location(index, inventory);

    if (item_ptr == NULL)
    {
        messages_println("ERROR 2");        
        return;
    }

    /* put the item on */

    switch( item_ptr->item_class)
    {
        case ring_class :
            equip_ring_b(item_ptr);
            break;
        default :
            messages_println("CANNOT EQUIP THAT");
            break;
    }

    calculate_stats_b();

}

void player_inventory_takeoff_b(creature_t *creature_ptr)
{
    uint8_t max;
    uint8_t index;
    entity_item_t *item_ptr;     
        
    max = ui_display_items(wearing);

    if (max == 0)
    {
        messages_println("NO ITEMS TO UNEQUIP");
        return;
    }

    messages_println("SELECT ITEM TO UNEQUIP OR SPACE TO EXIT"); 
    
    index = ui_select_item(max);

    if (index == 0)
    {
        return;        
    }

    item_ptr = entity_item_get_nth_at_location(index, wearing);

    if (item_ptr == NULL)
    {
        // Should never get here
        messages_println("ERROR 4");
        return;
    }    

    unequip_b(item_ptr);

    calculate_stats_b();    
}

void player_inventory_drop_b(creature_t *creature_ptr)
{
uint8_t max;
    uint8_t index;
    uint8_t i = 1;    
    entity_item_t *item_ptr;

    max = ui_display_items(inventory);

    if (max == 0)
    {
        messages_println("NO ITEMS TO DROP");
        return;
    }

    messages_println("SELECT ITEM TO DROP OR SPACE TO EXIT"); 

    index = ui_select_item(max);

    if (index == 0)
    {       
        return;        
    }

    item_ptr = entity_item_get_nth_at_location(index, inventory);

    if (item_ptr == NULL)
    {
        messages_println("ERROR 5");        
        return;
    }

    /* drop item */
    messages_println("YOU DROP ITEM");
    item_ptr->entity_ptr->location = dungeon;
    item_ptr->entity_ptr->x = creature_ptr->entity_ptr->x;
    item_ptr->entity_ptr->y = creature_ptr->entity_ptr->y;
  
}

static void equip_ring_b(entity_item_t *item_ptr)
{
    if (player_equip_left_finger == NULL)
    {
        player_equip_left_finger = item_ptr;
        item_ptr->entity_ptr->location = wearing;
        messages_println("YOU EQUIP THE RING");
    }
    else if (player_equip_right_finger == NULL)
    {
        player_equip_right_finger = item_ptr;
        item_ptr->entity_ptr->location = wearing;
        messages_println("YOU EQUIP THE RING");
    }
    else
    {
        messages_println("TAKE OFF A RING FIRST");
    }   
}

static void unequip_b(entity_item_t *item_ptr)
{
    if (player_equip_left_finger == item_ptr)
    {
        player_equip_left_finger = NULL;
        item_ptr->entity_ptr->location = inventory;
        messages_println("YOU UNEQUIP THE RING");        
    } 
    else if (player_equip_right_finger == item_ptr)
    {
        player_equip_right_finger = NULL;
        item_ptr->entity_ptr->location = inventory;
        messages_println("YOU UNEQUIP THE RING");  
    }
}

void player_inventory_display_b(creature_t *creature_ptr)
{
    ui_display_items(inventory);

    messages_println("PRESS ANY KEY");    

    in_wait_nokey();
    in_wait_key(); 
}

static void calculate_stats_b()
{
    creature_player_ptr->strength = player_base_strength;
    creature_player_ptr->dexterity = player_base_dexterity; 
    creature_player_ptr->constitution = player_base_constitution;   
    creature_player_ptr->intelligence = player_base_intelligence;
    creature_player_ptr->wisdom = player_base_wisdom;
    creature_player_ptr->charisma = player_base_charisma;

    creature_player_ptr->ac = player_base_ac;

    creature_player_ptr->max_hp = player_base_max_hp;
    creature_player_ptr->curr_hp = player_base_curr_hp;
    creature_player_ptr->speed = player_base_speed;

    apply_affect_mod(player_equip_body);
    apply_affect_mod(player_equip_left_hand);
    apply_affect_mod(player_equip_right_hand);
    apply_affect_mod(player_equip_left_finger);
    apply_affect_mod(player_equip_right_finger);
    apply_affect_mod(player_equip_head);
}

/** 
 * TODO handle negative modifiers - ability scores must not go negative *
 */

static void apply_affect_mod(entity_item_t *item_ptr) 
{
    uint8_t affect;
    int8_t affect_mod = 0;

    if (item_ptr == NULL)
        return;

    affect = item_ptr->affect;
    affect_mod = item_ptr->affect_mod;

    switch (affect)
    {
    case affect_none:
        /* no affect */
        break;
    case affect_ac:
        creature_player_ptr->ac += affect_mod;
        break;

    default:
        /* should never get */
        break;
    }
}
