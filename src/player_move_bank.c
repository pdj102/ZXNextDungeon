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

#include "ai_pathfind.h"

#include "globaldata.h"

#include "text.h"
#include "text_token.h"

#include "object.h"
#include "object_list.h"
#include "object_move.h"

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

void player_move_b(int8_t dx, int8_t dy)
{
    if (object_move_by(globaldata.player.player_creature_p->obj_p, dx, dy))
    {
        globaldata.player.player_creature_p->energy = 0;

        //update AI path
        ai_pathfind(globaldata.player.player_creature_p->obj_p->x, globaldata.player.player_creature_p->obj_p->y);
        ai_pathfind_print();   
    }
}