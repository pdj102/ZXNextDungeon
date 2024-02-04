/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - attacking

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_attacking_melee_bank.h"

#include <stdint.h>

#include "ai_bank.h"
#include "ai_pathfind_bank.h"
#include "ai_pathfind_fast_a_star_bank.h"

#include "creature.h"
#include "creature_move.h"
#include "creature_melee_strike.h"

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
 * @brief AI turn - attacking
 * 
 * @param *attacker_p    Pointer to AI creature
 * 
 * Behaviour
 * AI will melee attack target 
 * 
 * 1) If target is dead switch to attacking with no target state
 * 
 * 2) If out of melee range move towards target 
 * 
 * 3) If in melee range attack
 * 
 * TODO switch to ranged attack if over a distance away
 * 
 * TODO can't find target switch to attacking with no target
 * 
 */
void ai_attacking_melee_b(creature_t *attacker_p)
{
    direction_t d;
    uint8_t distance;
    creature_t *target_p;

    target_p = attacker_p->ai.target;

    // Is target dead?
    if (target_p->hp == 0)
    {
        target_p->ai.state = ATTACKING_NO_TARGET;
        return;
    }

    // Melee strike if adjacent 
    // Distance to target
    distance = distance_manhattan_b(attacker_p->obj_p->x, attacker_p->obj_p->y, target_p->obj_p->x, target_p->obj_p->y);

    // In range of melee strike (adjacent either up, down, left or right)
    if ( distance== 1)
    {
        creature_melee_strike(attacker_p, target_p);
        return;
    }    

    // Move towards target
    ai_pathfind_fast_a_star_b(attacker_p->obj_p->x, attacker_p->obj_p->y, target_p->obj_p->x, target_p->obj_p->y);


    d = ai_pathfind_direction_b( attacker_p->obj_p->x, attacker_p->obj_p->y );

    switch (d)
    {
    case NO_DIR:
        break;
    case N:
        creature_move_by(attacker_p, 0, -1);
        break;
    case S:
        creature_move_by(attacker_p, 0, 1);
        break;
    case W:
        creature_move_by(attacker_p, -1, 0);
        break;
    case E:
        creature_move_by(attacker_p, 1, 0);
        break;
    default:
        break;
    }
}

void ai_lost_target_b( creature_t *creature_p )
{
    // TODO Add support for parties and select next target in party
    creature_p->ai.state = AWAKE;
    creature_p->ai.target = 0;      
}