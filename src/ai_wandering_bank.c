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
void ai_wandering_new_loc_b( ai_t *ai_p );

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
 */
void ai_wandering_b(ai_t *ai_p)
{
    creature_t *creature_p = ai_p->creature_p;

    switch (ai_p->sub_state)
    {
    case NO_SUB_STATE:
    case GOTO_NO_TARGET_SET:
    case GOTO_TARGET_REACHED:
        ai_wandering_new_loc_b(ai_p);
        break;

    case GOTO_NO_PATH_SET:
    case GOTO_PATH_SET:
        ai_goto_b(ai_p);
        #ifdef DEBUG_AI
            text_printf("wandering - move\n");
        #endif        
        break;

    case GOTO_NO_PATH_FOUND:
        ai_p->sub_state = GOTO_NO_TARGET_SET;

        #ifdef DEBUG_AI
            text_printf("wandering - no path found\n");
        #endif
        break;

    case WANDERING_NO_TARGET_FOUND:
        ai_p->state = RESTING;

        #ifdef DEBUG_AI
            text_printf("wandering - no target found\n");
        #endif
        break;

    default:
        break;
    }
}

void ai_wandering_new_loc_b(ai_t *ai_p)
{
    uint8_t try = 0;
    uint8_t success = 0;
    uint8_t x, y;

    creature_t *creature_p = ai_p->creature_p;

    do
    {
        x = rand() % DUNGEONMAP_WIDTH;
        y = rand() % DUNGEONMAP_HEIGHT;

        if (!dungeonmap_tile_flag_test(x, y, DGN_FLAG_BLK_ALL | DGN_FLAG_WALL))
        {
            success = pathfind_fast_a_star(creature_p->obj_p->x, creature_p->obj_p->y, x, y, ai_p->pathfind_page);
        }
        ++try;
    } while (!success && try < 5);

    if (success)
    {
        ai_set_goto_b(ai_p, x, y);

        #ifdef DEBUG_AI
                text_printf("wandering - new loc - ok\n");
        #endif
    }
    else
    {
        ai_p->state = WANDERING_NO_TARGET_FOUND;

        #ifdef DEBUG_AI
                text_printf("wandering - new loc - fail\n");
        #endif
    }
}