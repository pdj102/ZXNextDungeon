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

#include "ai.h"
#include "ai_attacking_melee_bank.h"
#include "ai_guarding_bank.h"
#include "ai_wandering_bank.h"

#include "creature.h"
#include "creature_list.h"
#include "creature_action_wait.h"

#include "object.h"

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

void ai_turn_b( ai_t *ai_p )
{
    creature_t *creature_p = ai_p->creature_p;

    #ifdef DEBUG_AI
        text_printf("AI: %t ", creature_p->obj_p->name_token);
    #endif

    // creature_p->energy = 0;

    switch (ai_p->state)
    {
        case SLEEPING:
            // TODO implement AI sleeping - e.g. react to sound and waking up
            creature_action_wait(ai_p->creature_p);
            #ifdef DEBUG_AI
                text_printf("sleep\n");
            #endif
            return;

        case RESTING:
            // TODO implement AI resting - e.g. reacting to sounds or seeing an enemy
            creature_action_wait(ai_p->creature_p);        
            #ifdef DEBUG_AI            
                text_printf("rest\n");
            #endif
            return;

        case GUARDING:
            ai_guarding_b(ai_p);
            return;

        case WANDERING:
            ai_wandering_b(ai_p);
            return;            

        case ATTACKING_MELEE:
            ai_attacking_melee_b(ai_p);
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

uint8_t ai_is_enemy_b(ai_t *ai_p, creature_t *target_p)
{
    creature_t *attacker_p = ai_p->creature_p;

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
void ai_is_attacked_b(ai_t *ai_p, creature_t *attacker_p)
{

    creature_t *target_p = ai_p->creature_p;

    // Has the creature been killed?
    if (target_p->hp == 0)
    {
        ai_p->state = DEAD;
    }

    switch (ai_p->state)
    {
        case SLEEPING:
            text_printf("%t WAKES UP\n", (unsigned int) target_p->obj_p->name_token);
            ai_p->state = ATTACKING_MELEE;
            ai_p->target = attacker_p;        
        case RESTING:
            ai_p->state = ATTACKING_MELEE;
            ai_p->target = attacker_p;
            break;
        case GUARDING:
            ai_p->target = attacker_p;
            break;
        case ATTACKING_MELEE:
            // TODO - possibly change target if attacker is different to current target
            // TODO - possibly flee 
            break;
        default:
            break;
    }
}


ai_state_t ai_base_state_b(object_subtype_e subtype)
{
    switch (subtype)
    {
    //HUMANOID
    // BEAST
    case BEAST_SNAKE:
        return WANDERING;

    // OOZE
    case OOZE_GREY:
    case OOZE_SLIME:
        return WANDERING;
        
    // PLANT     
    case PLANT_WITHERWEED:
        return GUARDING;        
        
    // UNDEAD

    default:
        return WANDERING;
    }
}
