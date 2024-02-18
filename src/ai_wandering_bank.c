/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - wandering

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_wandering_bank.h"

#include <stdint.h>
#include <stdlib.h>             // rand()

#include "ai.h"
#include "ai_bank.h"
#include "ai_goto_bank.h"

#include "creature.h"
#include "creature_move.h"

#include "object_move.h"

#include "pathfind.h"

#include "text.h"
#include "util.h"

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


/** 
 * @brief AI turn - wandering
 * 
 * @param *attacker_p    Pointer to AI creature
 * 
 * Behaviour
 * AI will wander the dungeon randomly
 * 
 * 1) If target has no goto location select a randon new goto location
 * 
 * 2) Move torwards goto location
 * 
 * 3) If unable to get to goto location select a new goto location
 * 
 * 4) If reached goto location select a new goto location
 * 
 */
void ai_wandering_b( ai_t *ai_p )
{

    goto_result_t r;

    creature_t *creature_p = ai_p->creature_p;

    // #1 No goto location - set goto location?
    if (ai_p->goto_x == 0)
    {
        do
        {
            ai_set_goto_b( ai_p, rand() % DUNGEONMAP_WIDTH, rand() % DUNGEONMAP_HEIGHT);
        } while (!pathfind_fast_a_star(creature_p->obj_p->x, creature_p->obj_p->y, ai_p->goto_x, ai_p->goto_y, ai_p->pathfind_page));
    }

    // #2 Move towards goto location
    r = ai_goto_b(ai_p);

    switch (r)
    {
    case GOTO_FAIL:
        text_printf("Wandering - fail\n");
        ai_p->goto_x = 0;
        break;
    case GOTO_REACHED:
        text_printf("Wandering - reached\n");
        ai_p->goto_x = 0;
        break;
    case GOTO_SUCCESS:
        text_printf("Wandering - success\n");
        break;
    default:
        break;
    }

}
