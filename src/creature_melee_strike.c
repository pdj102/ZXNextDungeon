/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - melee strike

    Creature attempts a melee strike on another creature

 ***************************************************/

#include <stdint.h>

#include "creature_melee_strike.h"

#include "creature.h"
#include "creature_damage.h"

#include "ai.h"

#include "dice.h"

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


uint8_t creature_melee_strike(creature_t *attacker_p, creature_t *target_p)
{
    uint8_t attack_roll;
    uint8_t damage_roll;
    
    // reduce attackers energy 
    attacker_p->energy = 0;

    attack_roll = dice_1d20() + attacker_p->melee.attack_bonus;

    text_printf("%t STRIKES %t ", (unsigned int)attacker_p->obj_p->name_token, (unsigned int)target_p->obj_p->name_token);

    if (attack_roll < target_p->ac)
    {
        // Miss
        text_printf("AND MISSES\n");
    }
    else
    {
        // Hit
        text_printf("AND HITS\n");
    
        damage_roll = dice_roll(&target_p->melee.damage_roll);
        creature_damage(target_p, damage_roll, attacker_p->melee.damage_type);
    }

    // Notify AI of attack
    if (target_p->creature_class == AI)
    {
        ai_is_attacked(target_p, attacker_p);
    }
    return 1;
}

