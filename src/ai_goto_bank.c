/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - goto x, y

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_goto_bank.h"

#include <stdint.h>

#include "ai_bank.h"
#include "pathfind.h"

#include "creature.h"
#include "creature_move.h"

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

uint8_t ai_set_goto_b(ai_t *ai_p, uint8_t x, uint8_t y)
{
    ai_p->goto_x = x;
    ai_p->goto_y = y;

    return ai_goto_setpath_b(ai_p);
}

uint8_t ai_goto_b(ai_t *ai_p)
{
    if (ai_p->sub_state == GOTO_NO_PATH_SET)
    {
        ai_goto_setpath_b(ai_p);
    }

    if (ai_p->sub_state == GOTO_PATH_SET)
    {
        ai_goto_move_b(ai_p);
    }

    if (ai_p->sub_state == GOTO_NO_PATH_FOUND)
    {
        return 0;
    }

    return 1;
}

uint8_t ai_goto_setpath_b(ai_t * ai_p)
{
    if (pathfind_fast_a_star(ai_p->creature_p->obj_p->x, ai_p->creature_p->obj_p->y, ai_p->goto_x, ai_p->goto_y, ai_p->pathfind_page))
    {
        ai_p->sub_state = GOTO_PATH_SET;

        return 1;
    }
    else
    {      
        ai_p->sub_state = GOTO_NO_PATH_FOUND;

        return 0;
    }
}

void ai_goto_move_b(ai_t * ai_p)
{
    direction_t d;

    // Get direction from current path
    d = pathfind_direction( ai_p->creature_p->obj_p->x, ai_p->creature_p->obj_p->y, ai_p->pathfind_page );

    // If no direction information set, change state to no path set
    if (d == NO_DIR)
    {
        ai_p->sub_state = GOTO_NO_PATH_SET;
        return;
    }

    // Attempt move along path
    if (!creature_move_dir(ai_p->creature_p, d))
    {
        // Unable to move along path
        // TODO can we open a door?
        
        ai_p->sub_state = GOTO_NO_PATH_SET;

        #ifdef DEBUG_AI
            text_printf(" blocked\n");
        #endif 

        return;
    }

    // Has target location been reached?
    if ((ai_p->creature_p->obj_p->x == ai_p->goto_x) && (ai_p->creature_p->obj_p->y == ai_p->goto_y))
    {
        ai_p->sub_state = GOTO_TARGET_REACHED;

        #ifdef DEBUG_AI
            text_printf(" reached\n");
        #endif 

        return;        
    }

    #ifdef DEBUG_AI
        text_printf("\n");
    #endif     
}