/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief The player code - move action

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "player_bank.h"

#include <stdint.h>

#include "player.h"
#include "player_move_bank.h"

#include "globaldata.h"

#include "creature.h"
#include "creature_move.h"


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

void player_move_b(int8_t dx, int8_t dy)
{
    // TODO call creature move and deal with not being able to move e.g. due to an effect or status

    if (creature_move_by(globaldata.player.player_creature_p, dx, dy))
    {
        globaldata.player.player_creature_p->energy = 0;
    }
}