/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   Player inventory

 ***************************************************/
#include "player_inventory.h"

#include <input.h>      //  in_WaitForKey()
#include <stdio.h>      // NULL

#include "entity_item.h"

#include "text.h"
#include "messages.h"


#pragma output CRT_ORG_CODE = 0xC000 


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/


/***************************************************
 * variables
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/


void player_inventory_display_b(creature_t *creature_ptr)
{
    item_t *item_ptr;

    char s[] = "25500";     // string buffer for converting numbers to strings

    uint8_t count = 0;

    text_print_string(24, 0, "INVENTORY");

    item_ptr = entity_item_first_at_location(inventory);

    while ( item_ptr != NULL)
    {
        text_print_char(24, 2+count, 'A'+count);
        text_print_string(26, 2+count, item_ptr->name );
        count++;        

        item_ptr = entity_item_next_at_location(inventory, item_ptr);
    }

    in_wait_nokey();
    in_wait_key(); 
}