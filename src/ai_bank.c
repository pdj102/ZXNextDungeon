/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief AI code

    Code is banked do not call directly

 ***************************************************/

#pragma output CRT_ORG_CODE = 0xC000

#include "ai_bank.h"

#include <stdint.h>
#include <stdlib.h>         // abs()

#include "ai_attacking_melee_bank.h"
#include "ai_guarding_bank.h"
#include "ai_pathfind_bank.h"

#include "creature.h"
#include "creature_list.h"

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

void ai_turn_b( creature_t *creature_p )
{
    creature_p->energy = 0;

    switch (creature_p->ai.state)
    {
        case SLEEPING:
            return;

        case GUARDING:
            ai_guarding_b(creature_p);
            return;

        case ATTACKING_MELEE:
            ai_attacking_melee_b(creature_p);
            return;

        case ATTACKING_RANGED:
            // TODO implement ai attacking ranged
            return;            

        case ATTACKING_NO_TARGET:
            // TODO implement ai attacking no target
            return;

        case HUNTING:
            // TODO implement ai hunting
            return;

        case FLEEING:
            // TODO implement ai fleeing
            return;            
        
        case NO_STATE:
        case DEAD:
        default:
            return;
    }
}

uint8_t ai_is_enemy_b(creature_t *attacker_p, creature_t *target_p)
{
    // Ignore self
    if (attacker_p == target_p)
    {
        return 0;
    }

    // Plant logic
    if (attacker_p->obj_p->type == PLANTS)
    {
        // Ignore other plants
        if (target_p->obj_p->type == PLANTS)
        {
            
            return 0;
        }
        else
        {
            // attack everything else
            return 1;
        }
    }

    // Ooze logic
    if (attacker_p->obj_p->type == OOZE)
    {
        // Ignore other ooze
        if (target_p->obj_p->type == OOZE)
        {
            
            return 0;
        }
        else
        {
            // attack everything else
            return 1;
        }
    }     

    // TODO Implement is enemy logic for HUMANOID
    // TODO Implement is enemy logic for BEAST
    // TODO Implement is enemy logic for UNDEAD

    // Assume all other targets are an enemy
    return 1;
}

/**
 * Notify AI of an attack by another creature
 * 
 * @return void
 */
void ai_is_attacked_b(creature_t *target_p, creature_t *attacker_p)
{
    // Has the creature been killed?
    if (target_p->hp == 0)
    {
        target_p->ai.state = DEAD;
    }

    switch (target_p->ai.state)
    {
        case SLEEPING:
            text_printf("%t WAKES UP\n", (unsigned int) target_p->obj_p->name_token);
            target_p->ai.state = ATTACKING_MELEE;
            target_p->ai.target = attacker_p;        
        case AWAKE:
            target_p->ai.state = ATTACKING_MELEE;
            target_p->ai.target = attacker_p;
            break;
        case GUARDING:
            target_p->ai.target = attacker_p;
            break;
        case ATTACKING_MELEE:
            // TODO - possibly change target if attacker is different to current target
            // TODO - possibly flee 
            break;
        default:
            break;
    }
}

uint8_t distance_manhattan_b(uint8_t x1, uint8_t y1,uint8_t x2, uint8_t y2)
{
    uint8_t x = x1 > x2 ? x1 - x2 : x2 - x1;
    uint8_t y  = y1 > y2 ? y1 - y2 : y2 - y1;

    return x + y;
}
