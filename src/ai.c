/***************************************************
    Dungeon - ZX Spectrum Next 
    Paul Johnson

   AI 

 ***************************************************/
#include "ai.h"

#include <input.h>      //  in_WaitForKey()

#include "ai_pathfind.h" 

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
 * variables
 ***************************************************/


/***************************************************
 * functions
 ***************************************************/


void ai_turn(creature_t *creature_ptr)
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

        dir = ai_pathfind_direction_to_player(&pos);
        messages_print_s_int8("X", pos.x);
        messages_print_s_int8("Y", pos.y);
        messages_print_s_int8("DIR", dir);
        messages_print_s_int8("X", dir_delta[dir][0]);
        messages_print_s_int8("Y", dir_delta[dir][1]);

        entity_creature_move_or_strike(creature_ptr, dir_delta[dir][0], dir_delta[dir][1]);

        // in_wait_nokey();
        // in_wait_key();  

    }
}