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

#include "object_destroy.h"

#include "creature.h"
#include "creature_action_melee_strike.h"

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
    const direction_t d = get_dir_or_cancel_b();

    if (d == NO_DIR)
    {
        return;
    }

    if ( ! creature_action_melee_strike_dir(globaldata.player.player_creature_p, d) )
    {
        text_printf("Nothing to strike here\n");
    }
}