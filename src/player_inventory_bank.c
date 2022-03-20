/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   Player inventory

   Banked code. Do not call directly

 ***************************************************/
#include "player_inventory_bank.h"

#include <input.h>      //  in_WaitForKey()
#include <stdio.h>      // NULL
#include <ctype.h>      // character classification e.g. toupper() 

#include "entity_item.h"
#include "entity_creature.h"

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

extern entity_item_t *player_wear_body;
extern entity_item_t *player_equip_left_hand;
extern entity_item_t *player_equip_right_hand;
extern entity_item_t *player_equip_left_finger;
extern entity_item_t *player_equip_right_finger;
extern entity_item_t *player_equip_head;


/***************************************************
 * function prototypes
 ***************************************************/

void wear_b(uint8_t item_num);

void equip_ring_b(entity_item_t *item_ptr);

/***************************************************
 * functions
 ***************************************************/

// TODO handle empty inventory better
void player_inventory_wear_b(creature_t *creature_ptr)
{
    unsigned char key;

    uint8_t count;

    count = ui_display_inventory();

    messages_println("SELECT ITEM TO EQUIP OR SPACE TO EXIT"); 

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    key = toupper(key);


    if (key == ' ')
    {
        messages_println("ABORT");
        return;
    } 

    if (key >= 'A' && key <= 'Z')
    {
        wear_b(key - 'A');      
    }
    else
    {
        messages_println("INVALID SELECTION");  
    }

}

void wear_b(uint8_t item_num)
{
    uint8_t count = 0;
    entity_item_t *item_ptr;

    item_ptr = entity_item_first_at_location(inventory);
    if (item_ptr == NULL)
    {
        return;
    }

    while (count < item_num)
    {
        count++;
        item_ptr = entity_item_next_at_location(inventory, item_ptr);

        if (item_ptr == NULL)
        {   
            messages_println("INVALID SELECTION");  
            /* no such item - return */
            return;
        }
    }

    /* put the item on */

    switch( item_ptr->item_class_type)
    {
        case ring_class :
            equip_ring_b(item_ptr);
            break;
        default :
            messages_println("CANNOT EQUIP THAT");
            break;
    }

    /* TODO recalculate bonuses */

}

void equip_ring_b(entity_item_t *item_ptr)
{
    if (player_equip_left_hand == NULL)
    {
        player_equip_left_hand = item_ptr;
        item_ptr->entity_ptr->location = wearing;
        messages_println("YOU EQUIP THE RING");
    }
    else if (player_equip_right_hand == NULL)
    {
        player_equip_right_hand = item_ptr;
        item_ptr->entity_ptr->location = wearing;
        messages_println("YOU EQUIP THE RING");
    }
    else
    {
        messages_println("TAKE OFF A RING FIRST");
    }
    
}

void player_inventory_display_b(creature_t *creature_ptr)
{
    ui_display_inventory();

    messages_println("PRESS ANY KEY");    

    in_wait_nokey();
    in_wait_key(); 
}

