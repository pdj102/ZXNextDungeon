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

#include "creature.h"
#include "creature_list.h"
#include "creature_melee_strike.h"
#include "creature_damage.h"

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
void ai_guarding_b(creature_t *attacker_p)
{
    creature_t *target_p;

    switch (attacker_p->obj_p->type)
    {
    case PLANTS:
        target_p = creature_list_first_is_a2_within_rect(attacker_p->obj_p->x - 1, attacker_p->obj_p->y - 1, attacker_p->obj_p->x + 1, attacker_p->obj_p->y + 1, attacker_p, ai_is_enemy_b); // NB +/1 never outside dugneaon map
        if (target_p)
        {
            creature_melee_strike(attacker_p, target_p);
        }
        break;

    case HUMANOID:
    case BEAST:
    case OOZE:
    case UNDEAD:
        // if an enemy is within +/- 4 range set as target and switch state to attacking melee 
        target_p = creature_list_first_is_a2_within_square(attacker_p->obj_p->x, attacker_p->obj_p->y, 4, attacker_p, ai_is_enemy_b);
        if (target_p)
        {
            text_printf("%t targets %t\n", attacker_p->obj_p->name_token, target_p->obj_p->name_token);
            attacker_p->ai.state = ATTACKING_MELEE;
            attacker_p->ai.target = target_p;
        }
        break;

    default:
        break;
    }
}
