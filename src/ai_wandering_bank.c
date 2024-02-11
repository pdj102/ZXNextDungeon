/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - wandering

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_wandering_bank.h"

#include <stdint.h>

#include "ai_bank.h"

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
void ai_wandering_b(creature_t *creature_p)
{
    direction_t d;

    // No goto location - set goto location?
    if (creature_p->ai.goto_x == 0)
    {
        creature_p->ai.goto_x = 20;
        creature_p->ai.goto_y = 5;
    }

    // creature_move_dir(creature_p, 3);
    // creature_move_by(creature_p, 0, 1);
    // object_move_by(creature_p->obj_p, 1, 0);

    pathfind_fast_a_star(creature_p->obj_p->x, creature_p->obj_p->y, creature_p->ai.goto_x, creature_p->ai.goto_y);

    d = pathfind_direction( creature_p->obj_p->x, creature_p->obj_p->y );
    switch (d)
    {
    case N:
        text_printf("N\n");
        break;
    case S:
        text_printf("N\n");
        break;        
    case W:
        text_printf("W\n");
        break;
    case E:
        text_printf("E\n");
        break;                
    }
    text_printf("Name %t\n", creature_p->obj_p->name_token);
    // creature_move_dir(creature_p, d);

    // todo 3
    // todo 4

}
