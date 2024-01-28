/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - inventory list and actions

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>
#include <input.h>              // Functions for Reading Keyboards, Joysticks and Mice

#include "player.h"
#include "player_inventory_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"

#include "creature.h"


/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/
uint8_t not_wielding_b(object_t *obj_p);

/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

//TODO dedupe common inventory and equipment code

void player_inventory_list_b( void )
{
    object_t *obj_p;
    unsigned char index = 'a';
    unsigned int key;    


    // obj_p = object_list_first(globaldata.player.player_creature_p->obj_p);
    obj_p = object_list_first_is(globaldata.player.player_creature_p->obj_p, not_wielding_b );
    
    if (!obj_p)
    {
        text_printf("There is nothing in your inventory\n");
        return;
    }
    
    text_select_win( WIN_LARGE);
    text_cls();

    while (obj_p)
    {
        // text_printf("%c) ", index);
        // text_printf("%t\n", obj_p->name_token);
        text_printf("%c) %t\n", (char)index, (uint16_t)obj_p->name_token);        

        index++;
        // obj_p = object_list_next(obj_p);
        obj_p = object_list_next_is(globaldata.player.player_creature_p->obj_p, not_wielding_b );
    }

    text_printf("\n Press any key\n");
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key 

    text_select_win( WIN_MESSAGES);
}

object_t *player_inventory_select_object_is_a_b( object_is_a is_a_p )
{
    object_t *obj_p;
    uint8_t letter_max = 'a';
    uint8_t index, index_current;
    unsigned int key;    

    // Does the player have at least one item of the required type?
    obj_p = object_list_first_is2(globaldata.player.player_creature_p->obj_p, is_a_p, not_wielding_b);

    if (!obj_p)
    {
        text_printf("You have no items\n");
        return 0;
    }

    // Display the list of items of the required type
    text_select_win( WIN_LARGE);
    text_cls();

    while (obj_p)
    {
        text_printf("%c) %t\n", (char)letter_max, (uint16_t)obj_p->name_token);

        letter_max++;
        obj_p = object_list_next_is2(obj_p, is_a_p, not_wielding_b);
    }

    // User selects item or presses any other key to cancel
    text_printf("\nSelect item letter\n");
    text_select_win( WIN_MESSAGES);

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    if (! (key >= 'a' && key <= letter_max) )
    {
        // cancel
        return 0;
    }

    // Get the index of the selected object. 'A' is index 1, 'B' is 2 etc
    index = key - 'a';  

    // Find object at index 
    index_current = 1;
    obj_p = object_list_first_is(globaldata.player.player_creature_p->obj_p, is_a_p);

    while (index_current <= index)
    {
        obj_p = object_list_next_is(obj_p, is_a_p);
        index_current++;
    }

    // return selected object
    return obj_p;
}


uint8_t not_wielding_b(object_t *obj_p)
{
    if (globaldata.player.armour == obj_p ||
        globaldata.player.melee_weapon == obj_p ||
        globaldata.player.ranged_weapon == obj_p ||
        globaldata.player.ring_left == obj_p ||
        globaldata.player.ring_right == obj_p)
    {
        return 0;
    }

    return 1;
}