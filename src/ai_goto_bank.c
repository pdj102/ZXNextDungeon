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

/** 
 * @brief AI turn - goto
 * 
 * Behaviour
 * 
 * Creature moves towards its target location
 * 
 * @return  true if can reach target
 */
uint8_t ai_set_goto_b(ai_t *ai_p, uint8_t x, uint8_t y)
{
    ai_p->goto_x = x;
    ai_p->goto_y = y;
    return 0;
}



/** 
 * @brief AI turn - Creature moves towards its target location
 * 
 */
uint8_t ai_goto_b(ai_t *ai_p)
{
    direction_t d;


    // #1 Get direction from current path
    d = pathfind_direction( ai_p->creature_p->obj_p->x, ai_p->creature_p->obj_p->y, ai_p->pathfind_page );

    // #2 No direction then calculate a new path
    if (d == NO_DIR)
    {
        if (!pathfind_fast_a_star(ai_p->creature_p->obj_p->x, ai_p->creature_p->obj_p->y, ai_p->goto_x, ai_p->goto_y, ai_p->pathfind_page))
        {
            // #3 Unable to find a path then fail. TODO dont hard fail if blocked due to creature in the way 
            return GOTO_FAIL;
        }
    }

    // #4 Attempt move along path
    if (!creature_move_dir(ai_p->creature_p, d))
    {
        // #5 Failed to move then fail. TODO dont hard fail if blocked due to creature in the way 
        return GOTO_FAIL;
    }

    // #6 Have the goal been reached?
    if ((ai_p->creature_p->obj_p->x == ai_p->goto_x) && (ai_p->creature_p->obj_p->y == ai_p->goto_y))
    {
        return GOTO_REACHED;
    }

    // #6 Moved along path towards goal, return success
    return GOTO_SUCCESS;
}

