/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - close action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_close_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_close.h"

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

void player_close_b( void )
{
    int8_t dx, dy;
    uint8_t x, y;

    object_t *obj_p;

    if (! (get_dir_or_cancel_b(&dx, &dy)) )
    {
        return;
    }

    x = globaldata.player.player_creature_p->obj_p->x + dx;
    y = globaldata.player.player_creature_p->obj_p->y + dy;

    if ( obj_p = object_dungeon_list_first_is_at(x, y, object_close_is))
    {
        globaldata.player.player_creature_p->energy = 0;

        if ( object_close(obj_p) )
        {
            text_printf("YOU CLOSE THE %t\n", (uint16_t) obj_p->name_token);
            return;
        }
    }
    text_printf("NOTHING TO CLOSE HERE\n");
}