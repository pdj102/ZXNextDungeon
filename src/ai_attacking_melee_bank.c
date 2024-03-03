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

#include "creature.h"
#include "creature_action_move.h"
#include "creature_action_melee_strike.h"

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
void ai_attacking_melee_b(ai_t *ai_p)
{
    uint8_t distance;
    creature_t *attacker_p = ai_p->creature_p;
    creature_t *target_p;

    target_p = ai_p->target;

    // Is target dead?
    if (target_p->hp == 0)
    {
        ai_p->state = ATTACKING_NO_TARGET;
        return;
    }

    // Melee strike if adjacent 
    // Distance to target
    distance = util_distance_manhattan(attacker_p->obj_p->x, attacker_p->obj_p->y, target_p->obj_p->x, target_p->obj_p->y);

    // In range of melee strike (adjacent either up, down, left or right)
    if ( distance== 1)
    {
        creature_action_melee_strike(attacker_p, target_p);
        return;
    }    

    // Move towards target
    // TODO chase target
    /*
    ai_pathfind_fast_a_star_b(attacker_p->obj_p->x, attacker_p->obj_p->y, target_p->obj_p->x, target_p->obj_p->y);


    d = ai_pathfind_direction_b( attacker_p->obj_p->x, attacker_p->obj_p->y );

    switch (d)
    {
    case NO_DIR:
        break;
    case N:
        creature_action_move_by(attacker_p, 0, -1);
        break;
    case S:
        creature_action_move_by(attacker_p, 0, 1);
        break;
    case W:
        creature_action_move_by(attacker_p, -1, 0);
        break;
    case E:
        creature_action_move_by(attacker_p, 1, 0);
        break;
    default:
        break;
    }
    */
}

void ai_lost_target_b( ai_t *ai_p)
{
    // TODO Add support for parties and select next target in party
    ai_p->state = RESTING;
    ai_p->target = 0;      
}