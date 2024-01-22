/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_bank.h"

#include <stdint.h>

#include "ai.h"

#include "dungeonmap.h"

#include "globaldata.h"
#include "globaldata_defines.h"

#include "text.h"

#include "object.h"
#include "object_list.h"

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

void ai_init_b(ai_t *ai_p)
{
    // globaldata.ai.ai_creature_p = creature_p;
}

void ai_turn_b( creature_t *creature_p )
{
    creature_p->energy = 0;
    #ifdef DEBUG_ERROR
        text_printf("DEBUG: AI TURN %t\n", creature_p->obj_p->name_token );
    #endif

    switch (creature_p->ai.state)
    {
        case SLEEPING:
            return;
        case GUARDING:
            // TODO see player attack or flee
            return;
        case ATTACKING:
            ai_attack(creature_p);
            return;
        default:
            return;
    }
}

void ai_attack( creature_t *creature_p )
{
    // TODO use creature move
    creature_move_by();
}

