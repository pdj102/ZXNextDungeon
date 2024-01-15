/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - open action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_open.h"

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

void player_open_b( void )
{
    int8_t dx, dy;
    uint8_t x, y;

    object_t *obj_p;

    if (! (get_dir_or_cancel_b(&dx, &dy)) )
    {
        return;
    }

    x = globaldata.player_creature_p->obj_p->x + dx;
    y = globaldata.player_creature_p->obj_p->y + dy;

    if ( obj_p = object_dungeon_list_first_is_at(x, y, object_open_is))
    {
        globaldata.player_creature_p->energy = 0;

        if ( object_open(obj_p) )
        {
            text_printf("YOU OPEN THE %t\n", (uint8_t) obj_p->name_token);

            return;
        }
    }
    text_printf("NOTHING TO OPEN HERE\n");
}