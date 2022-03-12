/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   Player inventory

 ***************************************************/
#include "player_inventory.h"

#include <input.h>      //  in_WaitForKey()
#include <stdio.h>      // NULL
#include <ctype.h>      // character classification e.g. toupper() 

#include "entity_item.h"

#include "entity_creature.h"

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

void player_inventory_wear_b(creature_t *creature_ptr)
{
    unsigned char key;

    player_inventory_display_b(creature_ptr);

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    key = toupper(key);

    if (key == ' ')
    {
        /* abort */
        return;
    }

    if (key == 'A')
    {
        wear_b(0);
    }

}

void wear_b(uint8_t item_num)
{
    uint8_t count = 0;
    item_t *item_ptr;

    item_ptr = entity_item_first_at_location(inventory);
    if (item_ptr == NULL)
    {
        return;
    }

    while (count < item_num)
    {
        item_ptr = entity_item_next_at_location(inventory, item_ptr);

        if (item_ptr == NULL)
        {
            /* no such item - return */
            return;
        }
    }

    /* put the item on */
    /* TODO is it wearable */
    /* TODO is there a slot free */
    /* TODO recalculate bonuses */
    item_ptr->entity_ptr->location = wearing;
    messages_println("YOU WEAR ITEM");

}

void player_inventory_display_b(creature_t *creature_ptr)
{
    item_t *item_ptr;

    char s[] = "25500";     // string buffer for converting numbers to strings

    uint8_t count = 0;

    player_inventory_blank_display_b();

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

void player_inventory_blank_display_b()
{
    uint8_t i;
    const char *blank_string = "               *";

    for (i = 0; i < TILE_MAP_HEIGHT - 8; i++)
    {
        text_print_string(24, i, blank_string);
    }
}