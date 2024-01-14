/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - drop action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_drop_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_drop.h"

#include "object_dungeon_list.h"

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

// TODO implement drop from inventory 
void player_drop_b( void )
{
    object_t *obj_p;

    if ( obj_p = object_drop_find_first(globaldata.player_creature_p->obj_p) )
    {
        globaldata.player_creature_p->energy = 0;

        object_drop(obj_p, globaldata.player_creature_p->obj_p);
        text_printf("YOU DROP THE %t\n", (uint8_t) obj_p->name_token);   
        return;     
    }
    text_printf("NOTHING TO DROP\n");
}