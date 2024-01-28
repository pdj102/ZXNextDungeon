/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - pickup action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_pickup_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_pickup.h"

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

void player_pickup_b( void )
{
    object_t *obj_p;

    if ( obj_p = object_dungeon_list_first_is_at(globaldata.player.player_creature_p->obj_p->x, globaldata.player.player_creature_p->obj_p->y, object_pickup_is))
    {
        globaldata.player.player_creature_p->energy = 0;

        object_pickup(obj_p, globaldata.player.player_creature_p->obj_p);
        text_printf("You pick up the %t\n", (unsigned int) obj_p->name_token);
        return;
    }
    text_print_string("Nothing to pick up here\n");
}