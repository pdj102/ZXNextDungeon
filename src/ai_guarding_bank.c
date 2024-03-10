/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code - guarding

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_guarding_bank.h"

#include <stdint.h>

#include "ai_bank.h"
#include "pathfind_bank.h"

#include "ai.h"

#include "creature.h"
#include "creature_list.h"
#include "creature_action_melee_strike.h"
#include "creature_take_damage.h"

#include "text.h"


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
 * @brief AI turn - guarding
 * 
 * @param *attacker_p    Pointer to AI creature
 * 
 * Behaviour
 * 
 * PLANTS 
 *      AI will attack enemy who comes in melee range 
 */
void ai_guarding_b( ai_t *ai_p)
{
    creature_t *target_p;
    creature_t *attacker_p = ai_p->creature_p;

    // reduce creatures energy 
    attacker_p->energy = 0;     

    switch (attacker_p->obj_p->type)
    {
    case PLANTS:
        // NB +/-1 never outside dugneaon map
        target_p = creature_list_first_is_a2_within_rect(attacker_p->obj_p->x - 1, attacker_p->obj_p->y - 1, attacker_p->obj_p->x + 1, attacker_p->obj_p->y + 1, ai_p, ai_is_enemy_b); 
        // target_p = 0; // TODO implement AI version
        if (target_p)
        {
            #ifdef DEBUG_AI
                text_printf("guarding - attack\n");
            #endif
            creature_action_melee_strike(attacker_p, target_p);
        }
        else
        {
            #ifdef DEBUG_AI
                text_printf("guarding - do nothing\n");
            #endif
        }
        break;

    case HUMANOID:
    case BEAST:
    case OOZE:
    case UNDEAD:
        // if an enemy is within +/- 4 range set as target and switch state to attacking melee 
        // target_p = creature_list_first_is_a2_within_square(attacker_p->obj_p->x, attacker_p->obj_p->y, 4, attacker_p, ai_is_enemy_b);
        target_p = 0; // TODO implement AI version
        if (target_p)
        {
            text_printf("%t targets %t\n", attacker_p->obj_p->name_token, target_p->obj_p->name_token);
            ai_p->state = ATTACKING_MELEE;
            ai_p->target = target_p;
        }
        break;

    default:
        break;
    }
}
