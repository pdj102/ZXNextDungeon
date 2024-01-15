/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - inventory action

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


/***************************************************
 * private variables - static
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/

void player_inventory_b( void )
{
    object_t *obj_p;
    unsigned char index = 'A';
    unsigned int key;    


    obj_p = object_list_first(globaldata.player.player_creature_p->obj_p);
    
    if (!obj_p)
    {
        text_printf("THERE IS NOTHING IN YOUR INVENTORY\n");
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
        obj_p = object_list_next(obj_p);
    }

    text_printf("\n PRESS ANY KEY\n");
    while ((key = in_inkey()) == 0) ;   // loop while no key pressed
    in_wait_nokey();    // wait no key 

    text_select_win( WIN_MESSAGES);
}