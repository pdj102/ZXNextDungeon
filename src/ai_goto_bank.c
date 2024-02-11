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
uint8_t ai_set_goto_b(creature_t *creature_p, uint8_t x, uint8_t y)
{
    creature_p->ai.goto_x = x;
    creature_p->ai.goto_y = y;
    return 0;
}



/** 
 * @brief AI turn - goto
 * 
 * Behaviour
 * 
 * Creature moves towards its target location
 */
uint8_t ai_goto_b(creature_t *creature_p)
{
    direction_t d;

    pathfind_fast_a_star(creature_p->obj_p->x, creature_p->obj_p->y, creature_p->ai.goto_x, creature_p->ai.goto_y );
    d = pathfind_direction(creature_p->obj_p->x, creature_p->obj_p->y);
    creature_move_dir(creature_p, d);
    return 0;
}

