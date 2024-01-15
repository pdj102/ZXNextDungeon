/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - quaff action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_quaff_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_quaff.h"

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

void player_quaff_b( void)
{
    object_t *obj_p;

    obj_p = select_object_from_inventory_b( object_quaff_is);

    if ( object_quaff(globaldata.player.player_creature_p, obj_p) )
    {
        globaldata.player.player_creature_p->energy = 0;

        text_printf("YOU QUAFF THE %t\n", (uint16_t)obj_p->name_token);
    }
}