/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Player code

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>
#include <input.h>              // Functions for Reading Keyboards, Joysticks and Mice
#include <ctype.h>              // character classification e.g. toupper() 

#include "player.h"
#include "player_open_bank.h"
#include "player_close_bank.h"
#include "player_pickup_bank.h"
#include "player_quaff_bank.h"
#include "player_drop_bank.h"
#include "player_strike_bank.h"
#include "player_inventory_bank.h"
#include "player_move_bank.h"

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"

#include "object_dungeon_list.h"

#include "creature.h"


/***************************************************
 * private types
 ***************************************************/


/***************************************************
 * private function prototypes
 ***************************************************/

void move_b(int8_t dx, int8_t dy);
void inventory_b( void );


/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void player_init_b(creature_t *creature_p)
{
    globaldata.player_creature_p = creature_p;
}

void player_turn_b( void )
{

    unsigned int key;

    // while ((key = in_Inkey()) == 0) ;   // loop while no key pressed
    // in_WaitForNoKey();    // wait no key
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key    

    switch(toupper(key)) {
        
        case 54:  // down
            player_move_b(0, 1);
            break;
        case 55:  // up
            player_move_b(0, -1);
            break;

        case 53:  // left
            player_move_b(-1, 0);
            break;

        case 56:  // right
            player_move_b(1, 0);
            break;

        case 'O':  // open
            player_open_b();
            break;

        case 'C':  // close
            player_close_b();
            break;            

        case 'P':  // pickup
            player_pickup_b();
            break;

        case 'D':  // drop
            player_drop_b();
            break;

        case 'A':  // strike
            player_strike_b();
            break;                            

        case 'I':  // show inventory
            player_inventory_b();
            break;

        case 'Q':  // show inventory
            player_quaff_b();
            break;             

        case '1':
            dungeonmap_scroll(-1, 0);
            break;
        case '2':
            dungeonmap_scroll(1, 0);
            break;
        case '3':
            dungeonmap_scroll(0, -1);
            break;
        case '0':
            dungeonmap_scroll(0, 1);
            break;
        default:
            // text_print_int8(24, 20, key);
            break;
    }
}

uint8_t get_dir_or_cancel_b(int8_t *dx, int8_t *dy)
{
    unsigned int key;

    // while ((key = in_Inkey()) == 0) ;   // loop while no key pressed
    // in_WaitForNoKey();    // wait no key
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key   

    switch (toupper(key))
    {

    case 54: // down
        *dx = 0;
        *dy = 1;
        return 1;

    case 55: // up
        *dx = 0;
        *dy = -1;
        return 1;

    case 53: // left
        *dx = -1;
        *dy = 0;
        return 1;

    case 56: // right
        *dx = 1;
        *dy = 0;
        return 1;

    default:
        return 0;
    }
}

object_t *select_object_from_inventory_b( object_is_a is_a_p )
{
    object_t *obj_p;
    uint8_t letter_max = 'A';
    uint8_t index, index_current;
    unsigned int key;    

    // Does the player have at least one item of the required type?
    obj_p = object_list_first_is(globaldata.player_creature_p->obj_p, is_a_p);

    if (!obj_p)
    {
        text_printf("YOU HAVE NO ITEMS\n");
        return 0;
    }

    // Display the list of items of the required type
    text_select_win( WIN_LARGE);
    text_cls();

    while (obj_p)
    {
        text_printf("%c) ", letter_max);
        text_printf("%t\n", obj_p->name_token);

        letter_max++;
        obj_p = object_list_next_is(obj_p, is_a_p);
    }

    // User selects item or presses any other key to cancel
    text_printf("\nSELECT ITEM LETTER\n");
    text_select_win( WIN_MESSAGES);

    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key

    if (! (key >= 'A' && key <= letter_max) )
    {
        // cancel
        return 0;
    }

    // Get the index of the selected object. 'A' is index 1, 'B' is 2 etc
    index = key - 'A';  

    // Find object at index 
    index_current = 1;
    obj_p = object_list_first_is(globaldata.player_creature_p->obj_p, is_a_p);

    while (index_current <= index)
    {
        obj_p = object_list_next_is(obj_p, is_a_p);
        index_current++;
    }

    // return selected object
    return obj_p;
}
