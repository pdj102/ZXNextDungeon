/***************************************************
    Dungeon - ZX Spectrum Next 
    @author Paul Johnson

    @brief Game creature action - melee strike

    Creature attempts a melee strike on another creature

 ***************************************************/

#include <stdint.h>

#include "creature_melee_strike.h"

#include "creature.h"
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

    const uint8_t a = attacker_p->obj_p->name_token;
    const uint8_t t = target_p->obj_p->name_token;  
    
    attacker_p->energy -= 100;

    attack_roll = dice_1d20() + attacker_p->melee_modifier;

    if (attack_roll < target_p->ac)
    {
        // Miss
        // TODO implement "You miss the" vs "Snake miss" 
        text_printf("%t MISS THE ", a);
        text_printf("%t\n", t);
        return 0;
    }
    else
    {
        // Hit
        damage_roll = dice_roll(&attacker_p->melee_damage_roll) + attacker_p->melee_modifier;
        // TODO implement "You hit the" vs "Snake hits" 
        text_printf("%t HIT THE ", a);
        text_printf("%t\n", t);
        return 1;
    }

}

