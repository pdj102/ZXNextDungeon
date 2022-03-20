/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   AI

   Banked code. Do not call directly

 ***************************************************/
#include "ai_bank.h"

#include "ai_pathfind_bank.h" 

#include "entity_creature.h"
#include "entity_creature_move.h"

#include "coord_type.h"

#include "messages.h"



#pragma output CRT_ORG_CODE = 0xC000 


/***************************************************
 * types
 ***************************************************/


/***************************************************
 * function prototypes
 ***************************************************/


/***************************************************
 * Private variables - static
 * private variables in banked code not supported by z88dk. Place them in asm file
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/


void ai_turn_b(creature_t *creature_ptr)
{
    direction_t dir;
    coord_t pos;
    
    if (creature_ptr->state == ASLEEP ) 
    {
        // do nothing
        return;
    }

    if (creature_ptr->state == ATTACKING ) 
    {
        // print_path();

        pos.x = creature_ptr->entity_ptr->x;
        pos.y = creature_ptr->entity_ptr->y;

        dir = ai_pathfind_direction_to_player_b(&pos);

        entity_creature_move_or_strike(creature_ptr, dir_delta[dir][0], dir_delta[dir][1]);

    }
}