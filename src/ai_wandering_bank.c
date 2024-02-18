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

#include "dungeonmap.h"

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
uint8_t ai_wandering_new_loc_b( ai_t *ai_p );

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
 * 2) If no target exit
 * 
 * 3) Move torwards goto location
 * 
 * 4) If unable to get to goto location select a new goto location
 * 
 * 5) If reached goto location select a new goto location
 * 
 */
void ai_wandering_b( ai_t *ai_p )
{
    goto_result_t r;

    creature_t *creature_p = ai_p->creature_p;

    text_printf("Wandering");

    // #1 No goto location - set goto location?
    if (ai_p->goto_target == 0)
    {
        if (ai_wandering_new_loc_b(ai_p))
        {
            text_printf(" - new loc");
        }
        else
        {
            text_printf(" - failed new loc");
        }
    }

    // #2 if no target 
    if (!ai_p->goto_target)
    {
        return;
    }

    // #3 Move towards goto location
    r = ai_goto_b(ai_p);

    switch (r)
    {
    case GOTO_FAIL:
        text_printf(" - fail\n");
        ai_p->goto_target = 0;
        break;
    case GOTO_REACHED:
        text_printf(" - reached\n");
        ai_p->goto_target = 0;
        break;
    case GOTO_SUCCESS:
        text_printf(" - success\n");
        break;
    default:
        break;
    }
}

uint8_t ai_wandering_new_loc_b( ai_t *ai_p )
{
    uint8_t try = 0;
    uint8_t success = 0;
    uint8_t x, y;
    
    creature_t *creature_p = ai_p->creature_p;

        do
        {
            x = rand() % DUNGEONMAP_WIDTH;
            y = rand() % DUNGEONMAP_HEIGHT;

            if (!dungeonmap_tile_is_blocked(x, y))
            {
                success = pathfind_fast_a_star(creature_p->obj_p->x, creature_p->obj_p->y, x, y, ai_p->pathfind_page);
            }

            if (success)
            {
                ai_set_goto_b( ai_p, x, y);
            }

            ++try;
        } while (!success && try < 5);

        return success;
}