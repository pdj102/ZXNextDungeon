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

    attacker_p->energy -= 100;

    attack_roll = dice_1d20() + attacker_p->melee_modifier;

    if (attack_roll >= target_p->ac)
    {
        uint8_t a, t;
        a = attacker_p->obj_p->name_token;
        t = target_p->obj_p->name_token;
        // TODO implement "You hit the" vs "Snake hits" 
        text_printf("MISS THE %t\n", t);
        text_printf("%u MISS THE %u \n", a, t);
        text_printf("SUBTYPE %u\n", target_p->obj_p->subtype);
        text_printf("TOKEN %u \n", target_p->obj_p->name_token);
        text_printf("NAME %t \n", target_p->obj_p->name_token);         
        return 0;
    }
    else
    {
        damage_roll = dice_roll(&attacker_p->melee_damage_roll) + attacker_p->melee_modifier;
        // TODO implement "You hit the" vs "Snake hits" 
        text_printf("%t HIT THE %t \n", attacker_p->obj_p->name_token, target_p->obj_p->name_token);
        return 1;
    }

}

