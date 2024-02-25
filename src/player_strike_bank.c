/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - strike action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_strike_bank.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_strike.h"
#include "object_destroy.h"

#include "creature.h"
#include "creature_list.h"
#include "creature_melee_strike.h"
#include "creature_damage.h"
#include "creature_destroy.h"

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

void player_strike_b( void )
{
    int8_t dx, dy;
    uint8_t x, y;

    creature_t *target_p;

    if (! (get_dir_or_cancel_b(&dx, &dy)) )
    {
        return;
    }

    x = globaldata.player.player_creature_p->obj_p->x + dx;
    y = globaldata.player.player_creature_p->obj_p->y + dy;

    if ( target_p = creature_list_first_is_a_at(x, y, object_strike_is))
    {
        globaldata.player.player_creature_p->energy = 0;

        creature_melee_strike(globaldata.player.player_creature_p, target_p);
    }
    else
    {
        text_printf("Nothing to strike here\n");
    }
}